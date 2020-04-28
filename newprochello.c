#include "kernHeaders.h"

struct proc_dir_entry *some_file; 

int prochello_open (struct inode *_inode, struct file *_file)
{
	pr_alert("Opened\n");
	return 0;
}

static struct file_operations fops = {

.open = prochello_open,

};

static int prochello_init(void)
{
	some_file=proc_create("newprochello", S_IRWXU | S_IRWXG | S_IRWXO, NULL,&fops);
	if (some_file)
	{
		pr_alert("Success\n");
		return 0;
	}
	return -42;
}

static void prochello_exit(void)
{
	remove_proc_entry("prochello",NULL);
}

module_init(prochello_init);
module_exit(prochello_exit);
MODULE_LICENSE("GPL");

