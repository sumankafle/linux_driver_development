# Makefile for building and testing SCULL kernel module

ifneq ($(KERNELRELEASE),)
    # Kernel module build flags
    ccflags-y := -std=gnu99 -DENABLE_DEBUG
    scull-objs := main.o fops.o
    obj-m := scull.o
else
    # Host-side build
    KERNELDIR ?= /lib/modules/$(shell uname -r)/build
    PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) CC=x86_64-linux-gnu-gcc-12 modules

# Optional test target to insert/remove module and check dmesg
# Usage: make test PARAMS="quantum=4000 qset=1000"
test: all
	@echo "Clearing dmesg..."
	sudo dmesg -C
	@echo "Loading scull.ko..."
	sudo insmod scull.ko
	@sleep 1
	sudo dmesg | tail -10
	@sleep 1

	@echo "Removing scull.ko..."
#sudo rmmod scull.ko
	@sleep 1
	@echo "Final dmesg output:"
	sudo dmesg | tail -10

.PHONY: clean
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

endif

# Optional per-file CFLAGS
CFLAGS_main.o := -DDEBUG
CFLAGS_fops.o := -DDEBUG
