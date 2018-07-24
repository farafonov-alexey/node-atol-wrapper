#include <locale>
#include <codecvt>
#include <string>
#include <cstdarg>
#include <vector>
#include <nan.h>
#include "libfptr10.h"

std::wstring s2ws(const std::string& str);
std::string ws2s(const std::wstring& wstr);
bool checkError(libfptr_handle fptr, int res, std::string &error);
const std::wstring v8s2ws(v8::Local<v8::String> str);
