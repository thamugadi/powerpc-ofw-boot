#include <ofw.h>

extern void (*ofw)();

void* ofw_interpret(char* cmd, int32_t* stack_args, int n_stack_args, int n_ret_args, int32_t* retaddr)
{
        struct
        {
                char* service;
                int32_t n_args;
                int32_t n_rets;
                char* arg1;
                int32_t argN[n_stack_args];
                int32_t ret1;
                int32_t retN[n_ret_args];
        } ofw_arg;

        SERVICE("interpret", 10, 1+n_stack_args, n_ret_args);

        ofw_arg.arg1 = cmd;

        int i;
        for (i = 0; i < n_stack_args; i++)
        {
                ofw_arg.argN[i] = stack_args[i];
        }

        ofw(&ofw_arg);

        *retaddr = ofw_arg.ret1;
        for (i = 1; i < n_ret_args+1; i++)
        {
                retaddr[i] = ofw_arg.retN[i];
        }

        return retaddr;
}

void* ofw_set_callback(void* addr)
{
	struct
	{
        	char* service;
        	int32_t n_args;
        	int32_t n_rets;
        	void* arg;
        	void* ret;
	} ofw_arg;

	SERVICE("set-callback", 13, 1, 1);

	ofw_arg.arg = addr;

	ofw(&ofw_arg);
	return ofw_arg.ret;
}

void ofw_set_symbol_lookup(void* sym_to_value, void* value_to_sym)
{
	struct
	{
		char* service;
		int32_t n_args;
		int32_t n_rets;
		void* arg1;
		void* arg2;
	} ofw_arg;

	SERVICE("set-symbol-lookup", 17, 2, 0);

	ofw_arg.arg1 = sym_to_value;
	ofw_arg.arg2 = value_to_sym;

	ofw(&ofw_arg);
}


