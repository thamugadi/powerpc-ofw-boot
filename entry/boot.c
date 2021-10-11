#include "boot.h"
void get_io_type(void)
{
        if (*(unsigned char*)__VRAM__BEIGE == beige) IO_TYPE = beige;
	else if (*(unsigned char*)__VRAM__MAC99 == mac99) IO_TYPE = mac99;

}
void init(void)
{
	if (IO_TYPE == beige)
	{
		for(;;); // unsupported yet.
	}
	else if (IO_TYPE == mac99)
	{
		p_vram = __VRAM__MAC99;
		p_bios = __BIOS__MAC99;
		p_mouse=__MOUSE__MAC99;
		p_keyboard=__KEYBOARD__MAC99;
	}
}

void main(void)
{
	get_io_type();
	init();
	for(;;)	
	{
		memcpy_24bit(0x81000000, p_mouse, 1, 0x100000);
	}
	
}

void fillscreen(unsigned char a, unsigned char b, unsigned char c, int n)
{
	init();
	for (unsigned int i = 0; i<n; i++)
	{
		//24-bit VGA
		*p_vram = 0;
		p_vram++;
		*p_vram = a;
		p_vram++;
		*p_vram = b;
		p_vram++;
		*p_vram = c;
		p_vram++;
	}
}
void memcpy(unsigned char* dest, unsigned char* src, int n)
{
	unsigned char* destination = dest;
	unsigned char* source = src;
	for (int i = 0; i<n; i++)
	{
		*destination = *source;
		destination++; source++;
	}
}
void memcpy_24bit(unsigned char* dest, unsigned char* src, int n, int size)
{
        unsigned char* destination = dest;
        unsigned char* source = src;
        for (int i = 0; i<n; i++)
        {
		for (int k = 0; k < size; k++)
		{
			*destination = 0;
			destination++; 
                	for (int j = 0; j < 3; j++)
			{
				*destination = *source;
				destination++;
			}
        	}
		source++;
	}
}

unsigned char u8_extract_bit(unsigned char n, unsigned char bit)
{
        return (n & (0b10000000 >> bit)) >> (7 - bit);
}

unsigned char u32_extract_bit(unsigned int n, unsigned char bit)
{
	return (n & (0x80000000 >> bit)) >> (31 - bit);
}
