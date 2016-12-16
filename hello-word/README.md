# How to run
1. Have the Makefile and hello.c in a same folder. `cd` to that folder
2. `make Makefile`
3. Insert the module into the kernel by `sudo insmod hello.ko`
3. View information about the module with `modinfo hello.ko`
4. See the message by viewing `kern.log` in `var/log`
