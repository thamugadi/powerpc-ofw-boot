." powerpc-ofw-boot : Booting through OpenFirmware..." cr
\ storing 0xBE for beige, 0x5A for mac99
\ cannot use superior, inferior, different symbols (bootinfo.txt)
: sup - dup abs = ;
: inf dup sup 1 + ; 
: diff = if 0 else -1 then ;

: fba frame-buffer-adr ;
: beige-vram 80000000 ; : mac99-vram 81000000 ;

variable run 
-1 run !

fba 100 dump

fba beige-vram = if  ." Beige" cr 7000 0 do 0BE i beige-vram + c! loop then 
fba mac99-vram = if  ." mac99" cr 7000 0 do 05A i mac99-vram + c! loop then
fba beige-vram diff fba mac99-vram diff and if  ." Hardware not supported." cr 0 run ! then

fba 100 dump

run @ 0 = if 1 0 do 0 +loop then


boot hd:,\boot\kernel.elf
