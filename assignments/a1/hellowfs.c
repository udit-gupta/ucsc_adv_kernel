#include <linux/init.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/in.h>
#include <linux/errqueue.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("STUDENT");
MODULE_DESCRIPTION("Printing File System Info");

extern struct file_system_type *file_systems;

static int __init sysint_init(void) { 
    printk(KERN_ALERT "File Systems:\n");
    struct file_system_type *fs_ptr;
    fs_ptr = file_systems;
    
    while(fs_ptr){
        printk(KERN_ALERT "%s\n",fs_ptr->name);
        fs_ptr = fs_ptr->next;    
    }

    return 0;
}

void sysint_exit(void) {
	printk("\n\n Bye, Bye, Module Unloaded \n\n");
}

module_init(sysint_init);
module_exit(sysint_exit);

