#
# linux/arch/etrax100/boot/compressed/Makefile
#
# create a compressed vmlinux image from the original vmlinux files and romfs
#

ifndef TOPDIR
TOPDIR = ../../../..
HPATH = $(TOPDIR)/include
export HPATH
endif


CC = gcc-cris -melf -I $(TOPDIR)/include
CFLAGS = -O2
LD = ld-cris
OBJCOPY = objcopy-cris

OBJECTS = head.o misc.o

# files to compress
SYSTEM = $(TOPDIR)/vmlinux.bin

all: vmlinuz

decompress.bin: $(OBJECTS)
	$(LD) -T decompress.ld -o decompress.o $(OBJECTS)
	$(OBJCOPY) -O binary --remove-section=.bss decompress.o decompress.bin
# save it for mkprod in the topdir.
	cp decompress.bin $(TOPDIR)


vmlinuz: piggy.img decompress.bin
	cat decompress.bin piggy.img > vmlinuz
	rm -f piggy.img

head.o: head.S
	$(CC) -D__ASSEMBLY__ -traditional -c head.S -o head.o

# gzip the kernel image

piggy.img: $(SYSTEM)
	cat $(SYSTEM) | gzip -f -9 > piggy.img

clean:
	rm -f piggy.img vmlinuz vmlinuz.o

depend:
	$(CC) -M *.S *.c > .depend

-include .depend
