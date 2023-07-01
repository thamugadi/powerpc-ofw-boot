#include <ofw.h>

extern void (*ofw)();

phandle child(phandle _child)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                phandle arg;
                phandle ret;
        } ofw_arg;

	SERVICE("child", 6, 1, 1);

        ofw_arg.arg = _child;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

phandle parent(phandle _parent)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                phandle arg;
                phandle ret;
        } ofw_arg;

	SERVICE("parent", 7, 1, 1);

        ofw_arg.arg = _parent;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

phandle instance_to_package(ihandle instance)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                ihandle arg;
                phandle ret;
        } ofw_arg;

	SERVICE("instance-to-package", 20, 1, 1);

        ofw_arg.arg = instance;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int getproplen(phandle node, char* name)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                phandle arg1;
                char* arg2;
                int ret;
        } ofw_arg;

	SERVICE("getproplen", 11, 2, 1);

        ofw_arg.arg1 = node;
        ofw_arg.arg2 = name;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int getprop(phandle node, char* name, uint8_t* buf, int buflen)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                phandle arg1;
                char* arg2;
                uint8_t* arg3;
                int arg4;
                int ret;
        } ofw_arg;

	SERVICE("getprop", 8, 4, 1);

        ofw_arg.arg1 = node;
        ofw_arg.arg2 = name;
        ofw_arg.arg3 = buf;
        ofw_arg.arg4 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int nextprop(phandle node, char* previous, uint8_t* buf)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                phandle arg1;
                char* arg2;
                uint8_t* arg3;
                int ret;
        } ofw_arg;

	SERVICE("nextprop", 9, 3, 1);

        ofw_arg.arg1 = node;
        ofw_arg.arg2 = previous;
        ofw_arg.arg3 = buf;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int setprop(phandle node, char* name, uint8_t* buf, int len)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                phandle arg1;
                char* arg2;
                uint8_t* arg3;
                int arg4;
                int ret;
        } ofw_arg;

        char _service[8] = "setprop";
        ofw_arg.service = _service;

        ofw_arg.n_args = 4;
        ofw_arg.n_rets = 1;
        ofw_arg.arg1 = node;
        ofw_arg.arg2 = name;
        ofw_arg.arg3 = buf;
        ofw_arg.arg4 = len;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}
  
int canon(char* device, uint8_t* buf, int buflen)   
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                char* arg1;
                uint8_t* arg2;
                int arg3;
                int ret;
        } ofw_arg;

	SERVICE("canon", 6, 3, 1);

        ofw_arg.arg1 = device;
        ofw_arg.arg2 = buf;
        ofw_arg.arg3 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

phandle finddevice(char* device)              
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                char* arg1;  
                int ret;
        } ofw_arg;

	SERVICE("finddevice", 11, 1, 1);

        ofw_arg.arg1 = device;

        ofw(&ofw_arg);
        return ofw_arg.ret;
}

int instance_to_path(ihandle instance, uint8_t* buf, int buflen)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                ihandle arg1;
                uint8_t* arg2;
                int arg3;
                int ret;
        } ofw_arg;

	SERVICE("instance-to-path", 17, 3, 1);

        ofw_arg.arg1 = instance;
        ofw_arg.arg2 = buf;
        ofw_arg.arg3 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;

}

int package_to_path(phandle package, uint8_t* buf, int buflen)
{
        struct
        {
                char* service;
                int n_args;
                int n_rets;
                ihandle arg1;
                uint8_t* arg2;
                int arg3;
                int ret;
        } ofw_arg;

	SERVICE("package-to-path", 16, 3, 1);

        ofw_arg.arg1 = package;
        ofw_arg.arg2 = buf;
        ofw_arg.arg3 = buflen;

        ofw(&ofw_arg);
        return ofw_arg.ret;

}

void* call_method(char* method, ihandle instance, ...)
{
}

