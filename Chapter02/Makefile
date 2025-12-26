# Makefile for building and testing multiple kernel modules with parameters
obj-m += helloworld.o helloworld_params.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

# Test both modules
# Usage: make test PARAMS="myint=42 mystr=Hi myarr=5,6,7"
test: all
	@echo "Clearing dmesg..."
	sudo dmesg -C
	@echo "Loading helloworld.ko..."
	sudo insmod helloworld.ko
	@sleep 1
	@echo "Removing helloworld.ko..."
	sudo rmmod helloworld.ko
	@sleep 1
	@echo "Loading helloworld_params.ko with parameters: $(PARAMS)"
	sudo insmod helloworld_params.ko $(PARAMS)
	@sleep 1
	@echo "Removing helloworld_params.ko..."
	sudo rmmod helloworld_params.ko
	@sleep 1
	@echo "Recent dmesg output:"
	dmesg | tail -n 20
