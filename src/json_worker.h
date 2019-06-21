#ifndef INCLUDE_JSON_ASYNC_WORKER
#define INCLUDE_JSON_ASYNC_WORKER

#include <string>
#include <nan.h>
#include "fptr10.h"

class Fptr10;

class JsonWorker : public Nan::AsyncWorker {
public:
    JsonWorker(Fptr10* fptr10, std::wstring task, Nan::Callback *callback, void (*workerFinishedCallback)(Fptr10*));
    void Execute();
    void HandleOKCallback();
    void HandleErrorCallback();

private:
   Fptr10* fptr10_;
   std::wstring task_;
   int errorCode_;
   std::string strResult_;
   void (*workerFinishedCallback_)(Fptr10*);
};

#endif
