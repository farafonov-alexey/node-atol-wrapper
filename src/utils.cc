#include "utils.h"

std::wstring s2ws(const std::string& str)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;
    return converterX.from_bytes(str);
}

std::string ws2s(const std::wstring& wstr)
{
    using convert_typeX = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_typeX, wchar_t> converterX;
    return converterX.to_bytes(wstr);
}

bool checkErrorString(libfptr_handle fptr, int res, int &errorCode, std::string &errorDescr) {
    if(res == 0) return false;
    errorCode = libfptr_error_code(fptr);

    std::vector<wchar_t> errorDescription(32);
    std::string::size_type size = libfptr_error_description(fptr, &errorDescription[0], errorDescription.size());
    if (size > errorDescription.size())
    {
     errorDescription.resize(size);
     libfptr_error_description(fptr, &errorDescription[0], errorDescription.size());
    }
    errorDescr = ws2s(std::wstring(&errorDescription[0]));

    return true;
}

v8::Local<v8::Value> errorStringToErrorObject(int errorCode, const std::string& errorDescription) {
    std::string errorString = "Error "+ std::to_string(errorCode) +" [ " + errorDescription + " ]";
    v8::Local<v8::Object> errObj =
        Nan::To<v8::Object>(Nan::Error(Nan::New(errorString).ToLocalChecked())).ToLocalChecked();
    Nan::Set(errObj, Nan::New("code").ToLocalChecked(), Nan::New(errorCode));
    Nan::Set(errObj, Nan::New("description").ToLocalChecked(), Nan::New(errorDescription).ToLocalChecked());
    return (v8::Local<v8::Value>)errObj;
}

bool checkError(libfptr_handle fptr, int res, v8::Local<v8::Value>& error){
    int errorCode;
    std::string errorDescription;

    if (!checkErrorString(fptr, res, errorCode, errorDescription)) {
      return false;
    }

    error = errorStringToErrorObject(errorCode, errorDescription);
    return true;
}

const std::wstring v8s2ws(v8::Local<v8::String> str) {
    Nan::Utf8String utf8str(str); // take the string arg and convert it to v8::string
    std::string sStr(*utf8str); // take the v8::string convert it to c++ class string
    return s2ws(sStr);
}
