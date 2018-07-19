#include <stdio.h>
#include "fptr10.h"

Nan::Persistent<v8::FunctionTemplate> Fptr10::constructor;

NAN_MODULE_INIT(Fptr10::Init) {
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(Fptr10::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("Fptr10").ToLocalChecked());

  // link our getters and setter to the object property
  Nan::SetAccessor(ctor->InstanceTemplate(), Nan::New("x").ToLocalChecked(), Fptr10::HandleGetters, Fptr10::HandleSetters);

  Nan::SetPrototypeMethod(ctor, "test", Test);
  Nan::SetPrototypeMethod(ctor, "create", Create);
  Nan::SetPrototypeMethod(ctor, "getSettings", GetSettings);
  Nan::SetPrototypeMethod(ctor, "destroy", Destroy);

  target->Set(Nan::New("Fptr10").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Fptr10::New) {
  // throw an error if constructor is called without new keyword
  if(!info.IsConstructCall()) {
    return Nan::ThrowError(Nan::New("Fptr10::New - called without new keyword").ToLocalChecked());
  }

  // create a new instance and wrap our javascript instance
  Fptr10* fptr = new Fptr10();
  fptr->Wrap(info.Holder());

  // initialize it's values
  fptr->x = Nan::New(123.0) -> NumberValue();

  // return the wrapped javascript instance
  info.GetReturnValue().Set(info.Holder());
}

NAN_METHOD(Fptr10::Test) {
  // unwrap
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  self->x = self->x + 1.0;
  info.GetReturnValue().Set(Nan::New(self->x));
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
    self->x = value->NumberValue();
  }
}

NAN_METHOD(Fptr10::Create) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  libfptr_create(&(self->fptr));
  info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(Fptr10::Destroy) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  libfptr_destroy(&(self->fptr));
  info.GetReturnValue().Set(Nan::Undefined());
}

NAN_METHOD(Fptr10::GetSettings) {
  Fptr10* self = Nan::ObjectWrap::Unwrap<Fptr10>(info.This());
  wchar_t* settings = new wchar_t[1024];
//  std::vector<wchar_t> settings(1024);
  int size = libfptr_get_settings(self->fptr, &settings[0], 1024);
  if (size > 1024)
  {
      settings = new wchar_t[size];
      libfptr_get_settings(self->fptr, &settings[0], size);
  }
  printf("sett: %S\n", settings);

//  v8::Local<v8::String> json_string = Nan::New(settings).ToLocalChecked();
//
//  Nan::JSON NanJSON;
//  Nan::MaybeLocal<v8::Value> result = NanJSON.Parse(json_string);
//  if (!result.IsEmpty()) {
//    info.GetReturnValue().Set(result.ToLocalChecked());
//  } else {
    info.GetReturnValue().Set(Nan::Undefined());
//  }
}
