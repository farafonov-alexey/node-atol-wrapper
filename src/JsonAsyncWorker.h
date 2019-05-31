#ifndef INCLUDE_JSON_ASYNC_WORKER
#define INCLUDE_JSON_ASYNC_WORKER

#include <string>
#include <nan.h>
#include "fptr10.h"

class Fptr10;

class JsonAsyncWorker : public Nan::AsyncWorker {
public:
    std::wstring task;
    std::string strResult;
    Fptr10* fptr10;
    void (*workerFinishedCallback)(Fptr10*);
    int errorCode;

    JsonAsyncWorker(Fptr10* fptr10, std::wstring task, Nan::Callback *callback, void (*workerFinishedCallback)(Fptr10*));

    void Execute();
    void HandleOKCallback();
    void HandleErrorCallback();
};

#endif
