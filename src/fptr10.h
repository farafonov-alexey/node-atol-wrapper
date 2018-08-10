#include <nan.h>
#include "libfptr10.h"
#include "utils.h"

class Fptr10 : public Nan::ObjectWrap {
public:
  libfptr_handle fptr;
  double x;

  static NAN_MODULE_INIT(Init);
  static NAN_METHOD(New);
  static NAN_METHOD(Test);

  static NAN_METHOD(Create);
  static NAN_METHOD(Destroy);
  static NAN_METHOD(GetSettings);
  static NAN_METHOD(SetSettings);

  static NAN_METHOD(Open);
  static NAN_METHOD(Close);

  static NAN_METHOD(ProcessJson);
  static NAN_METHOD(FnReport);

  static NAN_GETTER(HandleGetters);
  static NAN_SETTER(HandleSetters);

  static Nan::Persistent<v8::FunctionTemplate> constructor;
};
