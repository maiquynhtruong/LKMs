#include <linux/module.h> // Needed for all modules
#include <linux/kernel.h> // Needed for KERN_INFO
#include <linux/init.h> // Needed for macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mai Truong");
MODULE_DESCRIPTION("A Hello World Loadable Kernel Module (LKM)");
MODULE_VERSION("0.1");

static int __init hello_start(void) {
        printk(KERN_INFO "Loading hello module...\n");
        printk(KERN_INFO "Hello World...\n");
        return 0;
}

static void __exit hello_end(void) {
        printk(KERN_INFO "Bye bye\n");
}

module_init(hello_start);
module_exit(hello_end);
~                       
