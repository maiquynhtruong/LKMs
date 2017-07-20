#include <linux/module.h> /* all kernel modules need this */
#include <linux/kernel.h> /* loglevels (KERN_WARNING, KERN_EMERG, KERN_INFO, etc.) */
#include <linux/init.h> /* __init and __exit macros */
#include <linux/slab.h> /* kmalloc */

// __init macros to show that this is the entry point into our LKM
static int __init on_load(void) {
	printk(KERN_EMERG "LKM loaded...\n");
	return 0;
}
static void __exit on_unload(void) {
	printk(KERN_EMERG "LKM unloaded...\n");
}
module_init(on_load);
module_exit(on_unload);
