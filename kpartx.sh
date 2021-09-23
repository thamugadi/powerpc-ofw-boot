#!/bin/sh

LOOP=$(sudo kpartx -s -a -v DISK.APM | awk -F'[ ]' '{print $3}' | tail -n1 )
sudo mkfs.hfsplus /dev/mapper/$LOOP
sudo mount -o loop /dev/mapper/$LOOP /mnt/
