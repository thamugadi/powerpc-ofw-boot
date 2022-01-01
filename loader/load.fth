." powerpc-ofw-boot : Booting through OpenFirmware..." cr
\ storing 0xBE for beige, 0x5A for mac99
\ cannot use superior, inferior, different symbols (bootinfo.txt)
: sup - dup abs = ;
: inf dup sup 1 + ; 
: diff = if 0 else -1 then ;
: fba frame-buffer-adr ;
: beige-vram 80000000 ; : mac99-vram 81000000 ;
: hardware-error ." Hardware not supported." ;

fba beige-vram = if ." Beige hardware detected" cr 0BE beige-vram c! then 
fba mac99-vram = if ." mac99 hardware detected" cr 05A mac99-vram c! then



fba beige-vram = if screen-width  4 beige-vram + l! then
fba beige-vram = if screen-height 8 beige-vram + l! then

fba mac99-vram = if screen-width  4 mac99-vram + l! then
fba mac99-vram = if screen-height 8 mac99-vram + l! then

variable run
-1 run !
fba beige-vram diff fba mac99-vram diff and if hardware-error cr 0 run ! then
run @ 0 = if 1 0 do 0 +loop then
." Running Game of Life: " cr
boot hd:,\boot\kernel.elf


