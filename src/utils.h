#ifndef INCLUDE_UTILS_H
#define INCLUDE_UTILS_H

#include "wcast_disable.h"

#include <locale>
#include <codecvt>
#include <string>
#include <cstdarg>
#include <vector>
DISABLE_WCAST_FUNCTION_TYPE
#include <nan.h>
DISABLE_WCAST_FUNCTION_TYPE_END
#include "libfptr10.h"

std::wstring s2ws(const std::string& str);
std::string ws2s(const std::wstring& wstr);
bool checkError(libfptr_handle fptr, int res, v8::Local<v8::Value> &error);
bool checkErrorString(libfptr_handle fptr, int res, int &errorCode, std::string& errorDescription);
v8::Local<v8::Value> errorStringToErrorObject(int errorCode, const std::string& errorDescription);
const std::wstring v8s2ws(v8::Local<v8::String> str);

#endif
