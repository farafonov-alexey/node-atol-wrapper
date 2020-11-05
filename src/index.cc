#include "wcast_disable.h"
#include "fptr10.h"

NAN_MODULE_INIT(InitModule) {
  Fptr10::Init(target);
}

DISABLE_WCAST_FUNCTION_TYPE
NODE_MODULE(node_atol_wrapper, InitModule);
DISABLE_WCAST_FUNCTION_TYPE_END