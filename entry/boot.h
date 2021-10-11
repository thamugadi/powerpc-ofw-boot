#define beige                   0xBE
#define mac99                   0x5A

#define __VRAM__BEIGE           0x80000000
#define __BIOS__BEIGE           0xFFC00000

#define __VRAM__MAC99           0x81000000
#define __BIOS__MAC99           0XFFF00000
#define __MOUSE__MAC99          0x8008003C
#define __KEYBOARD__MAC99       0x80080038
unsigned char  IO_TYPE;
unsigned char* p_vram;
unsigned char* p_bios;
unsigned char* p_keyboard;
unsigned char* p_mouse;

unsigned char u8_extract_bit(unsigned char n, unsigned char bit);
void get_io_type(void);
void init(void);
void fillscreen(unsigned char a, unsigned char b, unsigned char c, int n);
void memcpy(unsigned char* dest, unsigned char* src, int n);
void memcpy_24bit(unsigned char* dest, unsigned char* src, int n, int size);
unsigned char u8_extract_bit(unsigned char n, unsigned char bit);
unsigned char u32_extract_bit(unsigned int n, unsigned char bit);
