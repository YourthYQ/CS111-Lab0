#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry;

static int proc_count(struct seq_file *m, void *v)
{
	int count = 0;

	/* The `task_struct` is the kernel's internal representation of a process. 
 	 * This pointer will be used to iterate through all the processes.
   	 */
	struct task_struct *task;
	    
	/* for_each_process()
 	 * It's a macro used to iterate over each process in the task list of the Linux kernel. 
   	 * It's commonly used when you need to perform an action for every running process.
  	 */
	for_each_process(task) {
        	// Increment the count for each task found.
        	count++;
	}

	/* This function writes formatted output to the sequential file `m`. 
 	 * Here, it writes the final count of processes followed by a newline character. 
 	 */
	seq_printf("Current number of running processes: ", m, "%d\n", count);
	
	return 0;
}

static int __init proc_count_init(void)
{
	entry = proc_create_single("count", 0, NULL, proc_count);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("CS111 lab0 count proc number");
MODULE_LICENSE("GPL");
