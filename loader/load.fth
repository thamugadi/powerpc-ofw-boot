initmsg
fba beige-vram = if beige-message beige-magic-number beige-vram c! then 
fba mac99-vram = if mac99-message mac99-magic-number mac99-vram c! then
fba beige-vram = if screen-width  4 beige-vram + l! then
fba beige-vram = if screen-height 8 beige-vram + l! then
fba mac99-vram = if screen-width  4 mac99-vram + l! then
fba mac99-vram = if screen-height 8 mac99-vram + l! then
." informations stored :" cr
fba a dump
variable run
-1 run !
fba beige-vram diff fba mac99-vram diff and if hardware-error 0 run ! then
run @ 0 = if 1 0 do 0 +loop then
startmsg
boot hd:,\boot\kernel.elf
