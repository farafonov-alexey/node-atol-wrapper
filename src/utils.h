#include <locale>
#include <codecvt>
#include <string>
#include <cstdarg>
#include <vector>
#include <nan.h>
#include "libfptr10.h"

std::wstring s2ws(const std::string& str);
std::string ws2s(const std::wstring& wstr);
void checkError(libfptr_handle fptr, int res);
const std::wstring v8s2ws(v8::Local<v8::String> str);
