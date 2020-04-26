#include "kernHeaders.h"

extern void set_data (int);
extern int get_data (void);

static int entry(void)
{
	set_data(42);
	printk( KERN_ALERT "hello kernel, imported data changed\n");
	return 0;
}

static void escape(void)
{
	int data_v=0;
	data_v=get_data();
	printk( KERN_ALERT "bye kernel,we got data here %d\n",data_v);
}

module_init(entry);
module_exit(escape);

MODULE_LICENSE("GPL");
