PPC=powerpc-linux-gnu
APMdisk: kernel.elf bootinfo.txt kpartx.sh
	dd bs=8M count=2 if=/dev/zero of=APMdisk
	parted APMdisk --script mklabel mac mkpart primary hfs+ 32.8KB 100%
	sudo chmod +x kpartx.sh
	sudo ./kpartx.sh
	sudo mkdir /mnt/ppc
	sudo mkdir /mnt/boot
	sudo cp bootinfo.txt /mnt/ppc
	sudo cp kernel.elf /mnt/boot
	sudo umount /mnt/
	sudo kpartx -d APMdisk
bootinfo.txt: load.fs
	echo "<chrp-boot><boot-script>" >> bootinfo.txt
	cat load.fs >> bootinfo.txt
	echo "</boot-script></chrp-boot>" >> bootinfo.txt
kernel.elf: boot.elf
	$(PPC)-ld -Ttext=0x200000 boot.elf -o kernel.elf
boot.elf: boot.S
	$(PPC)-gcc -c boot.S -o boot.elf
clear:
	rm APMdisk *elf *txt
clean:
	rm APMdisk *elf *txt
