#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mai Truong");
MODULE_DESCRIPTION("LKM to reverse an input string");

static unsigned long buffer_size = 8192;
module_param(buffer_size, ulong, (S_IRUSR | S_IRGRP | S_IROTH));
MODULE_PARM_DESC(buffer_size, "Internel buffer size");

/**
Miscellaneous character device type, designed for small device drivers with a
single entry point. Misc devices share the same major number 10 and are controlled by one driver (/drivers/char/misc.c). They are distinguished by their minor numbers.
Declare struct miscdevice and call misc_register() with a pointer to the struct to register a minor number
**/
static struct file_operations reverse_fops = {
        .owner = THIS_MODULE,
        .open = reverse_open,
        .llseek = noop_llseek
};
static struct miscdevice reverse_misc_device = {
        .minor = MISC_DYNAMIC_MINOR,
        .name = "reverse",
        .fops = &reverse_fops // file operations, entry point to the module
};

static int __init reverse_init(void) {
        misc_register(&reverse_misc_device);
        if (!buffer_size)
                return -1;
        printk(KERN_INFO "Reverse device has been registered. Buffer size is %lu bytes\n", buffer_size);
        return 0;
}

