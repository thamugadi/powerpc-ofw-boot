initmsg
fba beige-fba = if beige-message beige-magic-number beige-fba c! then 
fba mac99-fba = if mac99-message mac99-magic-number mac99-fba c! then
fba beige-fba = if screen-width  4 beige-fba + l! then
fba beige-fba = if screen-height 8 beige-fba + l! then
fba mac99-fba = if screen-width  4 mac99-fba + l! then
fba mac99-fba = if screen-height 8 mac99-fba + l! then
variable run
-1 run !
fba beige-fba <> fba mac99-fba <> and if hardware-error 0 run ! then
run @ 0 = if 1 0 do 0 +loop then
boot hd:,\boot\kernel.elf
