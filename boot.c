#include "memory.h"
#define beige 0xBE
#define mac99 0x5A

void begin(void)
{
	unsigned char *ptr_beige = 0x80000000;
	unsigned char *ptr_mac99 = 0x81000000;
	if (*ptr_beige == beige) IO_TYPE = beige;
	if (*ptr_mac99 == mac99) IO_TYPE = mac99;
	init_ptr();
	clearscreen();
	for(;;);
}

void init_ptr(void)
{
	if (IO_TYPE == beige) vram_ptr = beige_vram;
	if (IO_TYPE == mac99) vram_ptr = mac99_vram;
}

void clearscreen(void)
{
	for (int i = 0; i<10000000; i++)
	{
		*vram_ptr = 0xFF;
		i++;
		vram_ptr++;
	}
}
