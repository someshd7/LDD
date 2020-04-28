#include "kernHeaders.h"

struct proc_dir_entry *some_file; 

static int prochello_init(void)
{
	some_file=proc_create("prochello", 0666, NULL,NULL);
	if (some_file==NULL)
	{
		pr_alert("Failure\n");
		return 42;
	}
	return 0;
}

static void prochello_exit(void)
{
	remove_proc_entry("prochello",some_file);
}

module_init(prochello_init);
module_exit(prochello_exit);
MODULE_LICENSE("GPL");

