#include <stdint.h>

#define SERVICE(name, len, args, rets) \
        char _service[len] = name; \
        ofw_arg.service = _service; \
        ofw_arg.n_args = args; \
        ofw_arg.n_rets = rets;

typedef int32_t phandle;
typedef int32_t ihandle;
