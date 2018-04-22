#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/signal.h>
asmlinkage long sh_task_info(long p,char* name)
{ 
   struct task_struct *task;
   int flag=0;
   for_each_process(task)
    {
       long pid = (long)task_pid_nr(task);
       if(p==pid)
        {
        	unsigned int f = (unsigned int)task->flags;
        	flag=1;
          printk("Process Name = %s\n PID = %ld\n Process priority = %ld\n Static priority = %ld\n Normal priority = %ld\n flags = %u\n",task->comm,(long)task_pid_nr(task),(long)task->prio,(long)task->static_prio,(long)task->normal_prio,f);
        }
    }
    printk("\n");
    if(flag==1)
    {
    	return 0;
    }
    else if(flag==0)
    {
    	printk("error no 1 : The process could not be found \n");
    	return 1;
    }
}
