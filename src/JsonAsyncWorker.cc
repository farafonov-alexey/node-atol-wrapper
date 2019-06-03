#include "JsonAsyncWorker.h"
#include "utils.h"



JsonAsyncWorker::JsonAsyncWorker(Fptr10* fptr10, std::wstring task, Nan::Callback *callback, void (*workerFinishedCallback)(Fptr10*))
    : Nan::AsyncWorker(callback) {

    this->fptr10 = fptr10;
    this->task = task;
    this->workerFinishedCallback = workerFinishedCallback;
  }

  void JsonAsyncWorker::Execute() {
      if (!this->task.empty()) {
          libfptr_set_param_str(this->fptr10->fptr, LIBFPTR_PARAM_JSON_DATA, &this->task[0]);
          v8::Local<v8::Value> error;
          std::string errorDescription;
          if(checkErrorString(this->fptr10->fptr, libfptr_process_json(this->fptr10->fptr), this->errorCode, errorDescription)){
            this->SetErrorMessage(errorDescription.c_str());
            return;
          }
          std::vector<wchar_t> result(256);
          int size = libfptr_get_param_str(this->fptr10->fptr, LIBFPTR_PARAM_JSON_DATA, &result[0], result.size());
          if (size > result.size())
          {
            result.resize(size);
            libfptr_get_param_str(this->fptr10->fptr, LIBFPTR_PARAM_JSON_DATA, &result[0], result.size());
          }
          std::wstring wRes = std::wstring(&result[0]);
          this->strResult = ws2s(wRes);
      } else {
          this->strResult = "";
      }
  }

  void JsonAsyncWorker::HandleOKCallback() {
    Nan::HandleScope scope;

    Nan::MaybeLocal<v8::Value> jsResult = Nan::Undefined();

    if (!this->strResult.empty()) {
      Nan::JSON NanJSON;
      jsResult = NanJSON.Parse(Nan::New(this->strResult).ToLocalChecked());
    }

    v8::Local<v8::Value> argv[] = {
      Nan::Null(), // no error occured
      jsResult.ToLocalChecked()
    };


    Nan::Call(callback->GetFunction(), Nan::GetCurrentContext()->Global(), 2, argv);
    this->workerFinishedCallback(this->fptr10);
  }

  void JsonAsyncWorker::HandleErrorCallback() {
    Nan::HandleScope scope;

    v8::Local<v8::Value> argv[] = {
      errorStringToErrorObject(this->errorCode, this->ErrorMessage()),
      Nan::Null()
    };

    Nan::Call(callback->GetFunction(), Nan::GetCurrentContext()->Global(), 2, argv);
    this->workerFinishedCallback(this->fptr10);
  }
