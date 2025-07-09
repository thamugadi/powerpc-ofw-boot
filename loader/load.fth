true to use-console?
false to ignore-output?
stdout @ 0= if
" screen" output
install-console
then
." hello!! :D" cr

: loader-location " :2,\boot\kernel.elf" ;

" dir " encode-bytes " &device;" encode-bytes 
encode+
" :2,\" encode-bytes encode+
evaluate

" load &device;" encode-bytes
loader-location encode-bytes
encode+
evaluate
go

variable run
0 run !
run @ 0 = if 1 0 do 0 +loop then 
