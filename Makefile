PPC=powerpc-linux-gnu
DISK.APM: kernel.elf bootinfo.txt kpartx.sh
	dd bs=512K count=2 if=/dev/zero of=DISK.APM
	parted DISK.APM --script mklabel mac mkpart primary hfs+ 32.8KB 100%
	sudo chmod +x kpartx.sh
	sudo ./kpartx.sh
	sudo mkdir /mnt/ppc
	sudo mkdir /mnt/boot
	sudo cp bootinfo.txt /mnt/ppc
	sudo cp kernel.elf /mnt/boot
	sudo umount /mnt/
	sudo kpartx -d DISK.APM
bootinfo.txt: load.fs
	echo "<chrp-boot><boot-script>" >> bootinfo.txt
	cat load.fs >> bootinfo.txt
	echo "</boot-script></chrp-boot>" >> bootinfo.txt
kernel.elf: boot.elf boot1.elf 
	$(PPC)-ld -Ttext=0x200000 boot.elf boot1.elf -o kernel.elf
boot1.elf: boot.c
	$(PPC)-gcc -c boot.c -o boot1.elf
boot.elf: boot.S
	$(PPC)-as -c boot.S -o boot.elf
clean:
	rm DISK.APM *elf *txt 
run:
	qemu-system-ppc DISK.APM
debug:
	qemu-system-ppc DISK.APM -d in_asm
all:
	make clean && make && make run
