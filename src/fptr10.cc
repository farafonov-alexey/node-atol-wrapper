#include <stdio.h>
#include "fptr10.h"
#include "utils.h"
#include "libfptr10.h"

using namespace v8;

Nan::Persistent<v8::FunctionTemplate> Fptr10::constructor;

NAN_MODULE_INIT(Fptr10::Init) {
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(Fptr10::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("Fptr10").ToLocalChecked());

  // link our getters and setter to the object property
  Nan::SetAccessor(ctor->InstanceTemplate(), Nan::New("x").ToLocalChecked(), Fptr10::HandleGetters, Fptr10::HandleSetters);

  Nan::SetPrototypeMethod(ctor, "create", Create);
  Nan::SetPrototypeMethod(ctor, "isOpened", IsOpened);
  Nan::SetPrototypeMethod(ctor, "destroy", Destroy);
  Nan::SetPrototypeMethod(ctor, "getSettings", GetSettings);
  Nan::SetPrototypeMethod(ctor, "setSettings", SetSettings);
  Nan::SetPrototypeMethod(ctor, "open", Open);
  Nan::SetPrototypeMethod(ctor, "close", Close);
  Nan::SetPrototypeMethod(ctor, "processJson", ProcessJson);
  Nan::SetPrototypeMethod(ctor, "processJsonAsync", ProcessJsonAsync);
  Nan::SetPrototypeMethod(ctor, "fnReport", FnReport);
  Nan::SetPrototypeMethod(ctor, "findLastDocument", FindLastDocument);

//  target->Set(Nan::New("Fptr10").ToLocalChecked(), ctor->GetFunction());
  Nan::Set(target, Nan::New("Fptr10").ToLocalChecked(), Nan::GetFunction(ctor).ToLocalChecked());
}

NAN_METHOD(Fptr10::New) {
  // throw an error if constructor is called without new keyword
  if(!info.IsConstructCall()) {
    return Nan::ThrowError(Nan::New("Fptr10::New - called without new keyword").ToLocalChecked());
  }

  // create a new instance and wrap our javascript instance
  Fptr10* fptr = new Fptr10();
  fptr->Wrap(info.Holder());

  // return the wrapped javascript instance
  info.GetReturnValue().Set(info.Holder());
}

NAN_GETTER(Fptr10::HandleGetters) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());

  std::string propertyName = std::string(*Nan::Utf8String(property));
  if (propertyName == "x") {
    info.GetReturnValue().Set(self->x);
  } else {
    info.GetReturnValue().Set(Nan::Undefined());
  }
}

NAN_SETTER(Fptr10::HandleSetters) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  if(!value->IsNumber()) {
    return Nan::ThrowError(Nan::New("expected value to be a number").ToLocalChecked());
  }
  std::string propertyName = std::string(*Nan::Utf8String(property));
  if (propertyName == "x") {
    self->x = value->NumberValue(Nan::GetCurrentContext()).ToChecked();
  }
}

NAN_METHOD(Fptr10::Create) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  v8::Local<v8::Value> error;
  if(checkError(self->fptr, libfptr_create(&(self->fptr)), error)){
     return Nan::ThrowError(error);
  }
  info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(Fptr10::Destroy) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  libfptr_destroy(&(self->fptr));
  info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(Fptr10::GetSettings) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  std::vector<wchar_t> settings(1024);
  std::string::size_type size = libfptr_get_settings(self->fptr, &settings[0], settings.size());
  if (size > settings.size())
  {
      settings.resize(size);
      libfptr_get_settings(self->fptr, &settings[0], settings.size());
  }
  std::string strSett = ws2s(std::wstring(&settings[0]));
  Nan::JSON NanJSON;
  Nan::MaybeLocal<v8::Value> result = NanJSON.Parse(Nan::New(strSett).ToLocalChecked());
  if (!result.IsEmpty()) {
    info.GetReturnValue().Set(result.ToLocalChecked());
  } else {
    info.GetReturnValue().Set(Nan::Undefined());
  }
}

NAN_METHOD(Fptr10::SetSettings) {
  // expect exactly 1 argument
  if(info.Length() != 1) {
    return Nan::ThrowError(Nan::New("Fptr10::SetSettings - expected 1 json argument").ToLocalChecked());
  }
  // argument must be object
  if(!info[0]->IsObject()) {
    return Nan::ThrowError(Nan::New("Fptr10::SetSettings - expected argument to be object").ToLocalChecked());
  }
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  Nan::JSON NanJSON;
  Nan::MaybeLocal<v8::String> result = NanJSON.Stringify(Nan::To<Object>(info[0]).ToLocalChecked());
  if (!result.IsEmpty()) {
    std::wstring wSett = v8s2ws(result.ToLocalChecked());
    v8::Local<v8::Value> error;
    if(checkError(self->fptr, libfptr_set_settings(self->fptr, &wSett[0]), error)){
      return Nan::ThrowError(error);
    }
    info.GetReturnValue().Set(Nan::True());
  } else {
    return Nan::ThrowError(Nan::New("Fptr10::SetSettings - expected argument to be non empty object").ToLocalChecked());
  }
}

NAN_METHOD(Fptr10::Open){
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  v8::Local<v8::Value> error;
  if(checkError(self->fptr, libfptr_open(self->fptr), error)){
     return Nan::ThrowError(error);
  }
  info.GetReturnValue().Set(Nan::True());
}

NAN_METHOD(Fptr10::IsOpened) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  bool isOpened = libfptr_is_opened(self->fptr) != 0;
  info.GetReturnValue().Set(Nan::New(isOpened));
}

NAN_METHOD(Fptr10::Close){
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  v8::Local<v8::Value> error;
  if(checkError(self->fptr, libfptr_close(self->fptr), error)){
     return Nan::ThrowError(error);
  }
  info.GetReturnValue().Set(Nan::True());
}

NAN_METHOD(Fptr10::ProcessJson){
   // expect exactly 1 argument
  if(info.Length() != 1) {
    return Nan::ThrowError(Nan::New("Fptr10::ProcessJsonSync - expected 1 json argument").ToLocalChecked());
  }
  // argument must be object
  if(!info[0]->IsObject()) {
    return Nan::ThrowError(Nan::New("Fptr10::ProcessJson - expected argument to be object").ToLocalChecked());
  }

  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  Nan::JSON NanJSON;
  Nan::MaybeLocal<v8::String> task = NanJSON.Stringify(Nan::To<Object>(info[0]).ToLocalChecked());
  if (!task.IsEmpty()) {
      std::wstring wSett = v8s2ws(task.ToLocalChecked());
      libfptr_set_param_str(self->fptr, LIBFPTR_PARAM_JSON_DATA, &wSett[0]);
      v8::Local<v8::Value> error;
      if(checkError(self->fptr, libfptr_process_json(self->fptr), error)){
         return Nan::ThrowError(error);
      }
      std::vector<wchar_t> result(256);
      std::string::size_type size = libfptr_get_param_str(self->fptr, LIBFPTR_PARAM_JSON_DATA, &result[0], result.size());
      if (size > result.size())
      {
        result.resize(size);
        libfptr_get_param_str(self->fptr, LIBFPTR_PARAM_JSON_DATA, &result[0], result.size());
      }
      std::wstring wRes = std::wstring(&result[0]);
      if(!wRes.empty()){
          std::string strResult = ws2s(wRes);
          Nan::JSON NanJSON;
          Nan::MaybeLocal<v8::Value> jsResult = NanJSON.Parse(Nan::New(strResult).ToLocalChecked());
          if (!jsResult.IsEmpty()) {
            info.GetReturnValue().Set(jsResult.ToLocalChecked());
          } else {
            info.GetReturnValue().Set(Nan::Undefined());
          }
      } else {
          info.GetReturnValue().Set(Nan::Undefined());
      }
  } else {
    info.GetReturnValue().Set(Nan::Undefined());
  }
}

NAN_METHOD(Fptr10::ProcessJsonAsync){
   // expect exactly 1 argument
  if(info.Length() != 2) {
    return Nan::ThrowError(Nan::New("Fptr10::ProcessJsonAsync - expected 2 arguments - json and callback function").ToLocalChecked());
  }
  // argument must be object
  if(!info[0]->IsObject()) {
    return Nan::ThrowError(Nan::New("Fptr10::ProcessJsonAsync - expected 1st argument to be object").ToLocalChecked());
  }
  // argument must be function
  if(!info[1]->IsFunction()) {
    return Nan::ThrowError(Nan::New("Fptr10::ProcessJsonAsync - expected 2nd argument to be function").ToLocalChecked());
  }

  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  Nan::JSON NanJSON;
  Nan::MaybeLocal<v8::String> task = NanJSON.Stringify(Nan::To<Object>(info[0]).ToLocalChecked());

  JsonWorker* newWorker = new JsonWorker(
      self,
      v8s2ws(task.ToLocalChecked()),
      new Nan::Callback(info[1].As<v8::Function>()),
      Fptr10::workerFinished
    );

  if (self->jsonAsyncTaskIsRunning) {
    self->taskQueue.push_back(newWorker);
  } else {
    self->jsonAsyncTaskIsRunning = true;
    Nan::AsyncQueueWorker(newWorker);
  }

//  Nan::AsyncQueueWorker(new JsonWorker(
//    self,
//    v8s2ws(task.ToLocalChecked()),
//    new Nan::Callback(info[1].As<v8::Function>())
//  ));

  info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(Fptr10::FnReport){
  // expect exactly 1 argument
  if(info.Length() != 1) {
    return Nan::ThrowError(Nan::New("Fptr10::FnReport - expected 1 integer argument").ToLocalChecked());
  }
  // argument must be object
  if(!info[0]->IsNumber()) {
    return Nan::ThrowError(Nan::New("Fptr10::FnReport - expected argument to be number").ToLocalChecked());
  }
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  libfptr_set_param_int(self->fptr, LIBFPTR_PARAM_REPORT_TYPE, LIBFPTR_RT_FN_DOC_BY_NUMBER);
  uint32_t value = Nan::To<uint32_t>(info[0]).FromJust();
  libfptr_set_param_int(self->fptr, LIBFPTR_PARAM_DOCUMENT_NUMBER, value);
  v8::Local<v8::Value> error;
  if(checkError(self->fptr, libfptr_report(self->fptr), error)){
     return Nan::ThrowError(error);
  }
  info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(Fptr10::FindLastDocument){
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  libfptr_set_param_int(self->fptr, LIBFPTR_PARAM_FN_DATA_TYPE, LIBFPTR_FNDT_LAST_DOCUMENT);
  v8::Local<v8::Value> error;
  if(checkError(self->fptr, libfptr_fn_query_data(self->fptr), error)){
     return Nan::ThrowError(error);
  }

  int documentNumber = libfptr_get_param_int(self->fptr, LIBFPTR_PARAM_DOCUMENT_NUMBER);

  std::vector<wchar_t> str(1024);
  std::string::size_type size = libfptr_get_param_str(self->fptr, LIBFPTR_PARAM_FISCAL_SIGN, &str[0], str.size());
  if (size > str.size())
  {
      str.resize(size);
      libfptr_get_param_str(self->fptr, LIBFPTR_PARAM_FISCAL_SIGN, &str[0], str.size());
  }
  std::string fiscalSign = ws2s(std::wstring(&str[0]));

  int year, month, day, hour, minute, second;
  libfptr_get_param_datetime(self->fptr, LIBFPTR_PARAM_DATE_TIME, &year, &month, &day, &hour, &minute, &second);
  v8::Local<v8::Object> date = Nan::New<v8::Object>();
  Nan::Set(date, Nan::New("year").ToLocalChecked(), Nan::New(year));
  Nan::Set(date, Nan::New("month").ToLocalChecked(), Nan::New(month));
  Nan::Set(date, Nan::New("day").ToLocalChecked(), Nan::New(day));
  Nan::Set(date, Nan::New("hour").ToLocalChecked(), Nan::New(hour));
  Nan::Set(date, Nan::New("minute").ToLocalChecked(), Nan::New(minute));
  Nan::Set(date, Nan::New("second").ToLocalChecked(), Nan::New(second));

  v8::Local<v8::Object> result = Nan::New<v8::Object>();
  Nan::Set(result, Nan::New("documentNumber").ToLocalChecked(), Nan::New(documentNumber));
  Nan::Set(result, Nan::New("fiscalSign").ToLocalChecked(), Nan::New(fiscalSign).ToLocalChecked());
  Nan::Set(result, Nan::New("date").ToLocalChecked(), date);
  info.GetReturnValue().Set(result);
}

void Fptr10::workerFinished(Fptr10* self) {
  if (self->taskQueue.empty()) {
    self->jsonAsyncTaskIsRunning = false;
  } else {
    JsonWorker* nextWorker = self->taskQueue.front();
    self->taskQueue.pop_front();
    Nan::AsyncQueueWorker(nextWorker);
  }
}
