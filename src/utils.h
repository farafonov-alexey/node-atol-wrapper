#ifndef INCLUDE_UTILS_H
#define INCLUDE_UTILS_H

#include <locale>
#include <codecvt>
#include <string>
#include <cstdarg>
#include <vector>
#include <nan.h>
#include "libfptr10.h"

std::wstring s2ws(const std::string& str);
std::string ws2s(const std::wstring& wstr);
bool checkError(libfptr_handle fptr, int res, v8::Local<v8::Value> &error);
bool checkErrorString(libfptr_handle fptr, int res, int &errorCode, std::string &errorDescription);
v8::Local<v8::Value> errorStringToErrorObject(int errorCode, std::string errorDescription);
const std::wstring v8s2ws(v8::Local<v8::String> str);

#endif
