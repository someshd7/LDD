#include "kernHeaders.h"


static int data=3;

static void set_data(int arg)
{
	data=arg;
}

static int get_data(void)
{
	return data;
}

static int entry(void)
{
	if(data==3)
		printk( KERN_ALERT "data was not initialized in commandline\n");
	else
		printk( KERN_ALERT "data was initialized in commandline\n");
	
	printk( KERN_ALERT "hello kernel,initialized data is=%d\n",data);
	return 0;
}

static void escape(void)
{
	printk( KERN_ALERT "hello.ko: bye kernel data is %d\n",data);
}

module_init(entry);
module_exit(escape);

module_param(data,int,S_IRUGO);

EXPORT_SYMBOL_GPL(set_data);
EXPORT_SYMBOL_GPL(get_data);
MODULE_LICENSE("GPL");
