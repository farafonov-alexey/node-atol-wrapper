#include <nan.h>
#include "fptr10.h"

NAN_MODULE_INIT(InitModule) {
  Fptr10::Init(target);
}

NODE_MODULE(node_atol_wrapper, InitModule);
