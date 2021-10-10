#define beige                   0xBE
#define mac99                   0x5A

#define __VRAM__BEIGE           0x80000000
#define __BIOS__BEIGE           0xFFC00000

#define __VRAM__MAC99           0x81000000
#define __BIOS__MAC99           0XFFF00000

unsigned char  IO_TYPE;
unsigned char* p_vram;
unsigned char* p_bios;
unsigned char* p_usb_keyboard;
unsigned char* p_usb_mouse;
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
	}
}

void main(void)
{
	get_io_type();
	init();
	//fillscreen(85,100,85, 0x100000);
	for(;;) 
	{
		memcpy(0x81000000, 0x81000001, 0x10000);
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
