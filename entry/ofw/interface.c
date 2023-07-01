#include <ofw.h>

extern void (*ofw)();

void* interpret(char* cmd, ...)
{
}

void* set_callback(void* addr)
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

void set_symbol_lookup(void* sym_to_value, void* value_to_sym)
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


