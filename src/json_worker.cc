#include "json_worker.h"
#include "utils.h"

JsonWorker::JsonWorker(Fptr10* fptr10, std::wstring task, Nan::Callback *callback, void (*workerFinishedCallback)(Fptr10*))
    : Nan::AsyncWorker(callback), fptr10_{fptr10}, task_{task}, workerFinishedCallback_{workerFinishedCallback}  {}

  void JsonWorker::Execute() {
      if (!task_.empty()) {
          libfptr_set_param_str(fptr10_->fptr, LIBFPTR_PARAM_JSON_DATA, &task_[0]);
          v8::Local<v8::Value> error;
          std::string errorDescription;
          if(checkErrorString(fptr10_->fptr, libfptr_process_json(fptr10_->fptr), errorCode_, errorDescription)){
            SetErrorMessage(errorDescription.c_str());
            return;
          }
          std::vector<wchar_t> result(256);
          std::string::size_type size = libfptr_get_param_str(fptr10_->fptr, LIBFPTR_PARAM_JSON_DATA, &result[0], result.size());
          if (size > result.size())
          {
            result.resize(size);
            libfptr_get_param_str(fptr10_->fptr, LIBFPTR_PARAM_JSON_DATA, &result[0], result.size());
          }
          std::wstring wRes = std::wstring(&result[0]);
          strResult_ = ws2s(wRes);
      } else {
          strResult_ = "";
      }
  }

  void JsonWorker::HandleOKCallback() {
    Nan::HandleScope scope;

    Nan::MaybeLocal<v8::Value> jsResult = Nan::Undefined();

    if (!strResult_.empty()) {
      Nan::JSON NanJSON;
      jsResult = NanJSON.Parse(Nan::New(strResult_).ToLocalChecked());
    }

    v8::Local<v8::Value> argv[] = {
      Nan::Null(), // no error occured
      jsResult.ToLocalChecked()
    };


    Nan::Call(callback->GetFunction(), Nan::GetCurrentContext()->Global(), 2, argv);
    workerFinishedCallback_(fptr10_);
  }

  void JsonWorker::HandleErrorCallback() {
    Nan::HandleScope scope;

    v8::Local<v8::Value> argv[] = {
      errorStringToErrorObject(errorCode_, ErrorMessage()),
      Nan::Null()
    };

    Nan::Call(callback->GetFunction(), Nan::GetCurrentContext()->Global(), 2, argv);
    workerFinishedCallback_(fptr10_);
  }
