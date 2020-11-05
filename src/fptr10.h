#ifndef INCLUDE_Fptr10
#define INCLUDE_Fptr10

#include "wcast_disable.h"

DISABLE_WCAST_FUNCTION_TYPE
#include <nan.h>
DISABLE_WCAST_FUNCTION_TYPE_END
#include <vector>
#include "json_worker.h"
#include "libfptr10.h"

class JsonWorker;

class Fptr10 : public Nan::ObjectWrap {
public:
  libfptr_handle fptr;
  double x;
  bool jsonAsyncTaskIsRunning = false;
  std::deque<JsonWorker*> taskQueue;

  static NAN_MODULE_INIT(Init);
  static NAN_METHOD(New);

  static NAN_METHOD(IsOpened);

  static NAN_METHOD(Create);
  static NAN_METHOD(Destroy);
  static NAN_METHOD(GetSettings);
  static NAN_METHOD(SetSettings);

  static NAN_METHOD(Open);
  static NAN_METHOD(Close);

  static NAN_METHOD(ProcessJsonAsync);
  static NAN_METHOD(ProcessJson);
  static NAN_METHOD(FnReport);
  static NAN_METHOD(FindLastDocument);

  static NAN_GETTER(HandleGetters);
  static NAN_SETTER(HandleSetters);

  static Nan::Persistent<v8::FunctionTemplate> constructor;
  static void workerFinished(Fptr10* self);
};

#endif
