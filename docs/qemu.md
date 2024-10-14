# Installation Guide

> [!IMPORTANT]
> This guide was written in Otcober 2024. While I try to keep the information as general as possible, as well as keeping the whole process up-to-date with the best of conscience, I do not guarantee for completeness. The installation method can differ depending on future changes and is subject to a general understanding of working with software and Windows. 

### Download and install QEMU

Stefan Weil provides executable binaries (=installers) for Windows, supporting either 32-bit or 64-bit systems. Choose the corresponding link for your system and download the latest ".exe" of the root directory.

Download the 32-bit version [here](https://qemu.weilnetz.de/w32/)

Download the 64-bit version [here](https://qemu.weilnetz.de/w64/)

After downloading, open and install QEMU in the default path (```C:\Program Files\qemu```). Also, leave all checkboxes checked when prompted in the additional package list while running the installer. 

### Add environmental variable to Windows

Add the path ```C:\Program Files\qemu``` to your system's path variable. I recommend adding it to your system variables instead of just user path variables. Tutorials on how you can do that are widely available in the internet. You can check if everything was successful to this point in time by opening a terminal and executing the command ```qemu-system-arm --version```. It should return something similar than of the time of writing, which is ```QEMU emulator version 9.1.0 (v9.1.0-12064-gc658eebf44)```
