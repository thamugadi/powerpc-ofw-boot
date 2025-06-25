#include <stdint.h>

#define SERVICE(name, len, args, rets) \
        char _service[len] = name; \
        ofw_arg.service = _service; \
        ofw_arg.n_args = args; \
        ofw_arg.n_rets = rets;

typedef int32_t phandle;
typedef int32_t ihandle;

void puts(char* str, int len);

void* ofw_interpret(char* cmd, int32_t* stack_args, int n_stack_args, int n_ret_args, int32_t* retaddr);
int32_t ofw_test(char* name);
