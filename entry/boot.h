#define beige                   0xBE
#define mac99                   0x5A

#define __VRAM__BEIGE           0x80000000
#define __BIOS__BEIGE           0xFFC00000
#define __TIMR__BEIGE           0x81080038 
#define __VRAM__MAC99           0x81000000
#define __BIOS__MAC99           0xFFF00000
#define __TIMR__MAC99           0x80080038
void __stack_chk_fail_local();

unsigned char  IO_TYPE;
unsigned int   screen_width;
unsigned int   screen_height;

unsigned char* p_vram;
unsigned char* p_bios;
unsigned char* p_timer;
unsigned char u8_extract_bit(unsigned char n, unsigned char bit);
void get_io_type(void);
void init(void);
void fillscreen(unsigned int* addr, unsigned char a, unsigned char b, unsigned char c, int n);
void memcpy(unsigned char* dest, unsigned char* src, int n);
unsigned char u8_extract_bit(unsigned char n, unsigned char bit);
unsigned char u32_extract_bit(unsigned int n, unsigned char bit);

