# Installation guide (LEGACY)

> [!IMPORTANT]
> This guide was written in October 2024. While I try to keep the information as general as possible, as well as keeping the whole process up-to-date with the best of conscience, I do not guarantee for completeness. The installation
> method can differ depending on future changes and is subject to a general understanding of working with software and Windows. 

### Download and install QEMU

Stefan Weil provides executable binaries (=installers) for Windows, supporting either 32-bit or 64-bit systems. Choose the corresponding link for your system and download the latest ".exe" of the root directory.

Download the 32-bit version [here](https://qemu.weilnetz.de/w32/)

Download the 64-bit version [here](https://qemu.weilnetz.de/w64/)

After downloading, open and install QEMU in the default path (```C:\Program Files\qemu```). Also, leave all checkboxes checked when prompted in the additional package list while running the installer. 

### Add environmental variable to Windows

Add the path ```C:\Program Files\qemu``` to your system's path variable. I recommend adding it to your system variables instead of just user path variables. Tutorials on how you can do that are widely available in the internet. You can check if everything was successful to this point in time by opening a terminal and executing the command ```qemu-system-arm --version```. It should return something similar than at the time of writing, which is ```QEMU emulator version 9.1.0 (v9.1.0-12064-gc658eebf44)```

### Download the RPi QEMU kernel

Download the zip file of the main branch of the repository by following this link [here](https://github.com/dhruvvyas90/qemu-rpi-kernel/archive/refs/heads/master.zip). After finishing downloading, extract the contents of the archive. Rename the inner root directory of the archive from ```qemu-rpi-kernel-master``` to ```qemu-rpi-kernel```

> [!NOTE]
> The file structure of the downloaded zip looks like the following: ```.\qemu-rpi-kernel-master.zip\qemu-rpi-kernel-master\...\```.
> Make sure to rename and only use the inner folder of archive: ```.\qemu-rpi-kernel-master\...\```.
> Just renaming the unzipped folder will **NOT** work later on!

### Download Pi OS image

We will use the lite version of Debian Bullseye (Debian 11). You can find a link [here](https://downloads.raspberrypi.org/raspios_oldstable_lite_armhf/images/raspios_oldstable_lite_armhf-2023-02-22/2023-02-21-raspios-buster-armhf-lite.img.xz). Download the image and inzip it so that the file ending will change from ```.img.xz``` to ```.img```. Normally, while doing so, Windows will generate a new folder where the binary ```.img``` is located. 

### Create image instance and run the VM

Create a new folder/directory on your drive and put the folder ```qemu-rpi-kernel``` as well as the ```.img``` file in there. Open a command line in this directory or navigate to the folder you just created by hand. 

After that, paste in the command down below. Your VM should start now!

```shell
qemu-system-arm -M versatilepb -cpu arm1176 -m 256 ^
-drive "file=./2023-02-21-raspios-buster-armhf-lite.img,if=none,index=0,media=disk,format=raw,id=disk0" ^
-device "virtio-blk-pci,drive=disk0,disable-modern=on,disable-legacy=off" ^
-net "user,hostfwd=tcp::5022-:22" ^
-dtb ./qemu-rpi-kernel/versatile-pb-buster-5.4.51.dtb ^
-kernel ./qemu-rpi-kernel/kernel-qemu-5.4.51-buster ^
-append "root=/dev/vda2 panic=1" ^
-no-reboot -net nic
```


