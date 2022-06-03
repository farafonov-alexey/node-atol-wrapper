#include "wcast_disable.h"
#include "fptr10.h"

NAN_MODULE_INIT(InitModule) {
  Fptr10::Init(target);
}

DISABLE_WCAST_FUNCTION_TYPE
#if NODE_MAJOR_VERSION >= 10
NAN_MODULE_WORKER_ENABLED(node_atol_wrapper, InitModule)
#else
NODE_MODULE(node_atol_wrapper, InitModule)
#endif
DISABLE_WCAST_FUNCTION_TYPE_END