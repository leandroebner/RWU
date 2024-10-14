#
# Linux makefile
# Use with make 
#

.SUFFIXES: .o .asm .c

AS=as
ASFLAGS= -g -o
CFLAGS= -g -march=armv8-a
CC=gcc


.asm.o:
	$(AS) $(ASFLAGS) $*.o $*.asm -al=$*.lst


.c.o:
	$(CC) -c $(CFLAGS) $*.c

all: Strldr

Strldr : strldr.o strldr_asm.o 
	$(CC) $(CFLAGS) -o Strldr strldr.o strldr_asm.o


strldr_asm.o : strldr_asm.asm


strldr.o : strldr.c


clean :
	rm *.o
	rm *.lst
	rm Strldr
debug :
	gdb ./Strldr -x gdb_command

