KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)
LDD  := /lib/modules/$(shell uname -r)/kernel/drivers/ldd

OBJ  := hellowfs
obj-m := $(OBJ).o

all: load clean
run: load unload
runall: loadall unload
runcleanall: loadall unload

compile: 
	echo "Now in Compile"
	@$(MAKE) -C $(KDIR) M=$(PWD) modules
	sudo mkdir -p $(LDD); sudo cp $(OBJ).ko $(LDD); sudo depmod -a

load: compile 
	echo "Now in load"
	sudo insmod ./$(OBJ).ko

loadall: compile
	echo "Now in loadall"
	sudo modprobe $(OBJ)

unload: 
	echo "Now in unload"
	sudo rmmod $(OBJ)

clean: unload
	echo "Now in clean"
	@rm -rf $(OBJ).o $(OBJ).ko $(OBJ).*.* .$(OBJ).* .tmp_versions* Module* module* 
 
