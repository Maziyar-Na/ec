#include "get_total_usage.h"
unsigned long get_usage(struct task_struct* task){
	unsigned long usage_in_bytes;
	struct mem_cgroup* memcg = mem_cgroup_from_task(task);
	
	usage_in_bytes = mem_cgroup_usage(memcg, false);
	return usage_in_bytes;
}


static int __init lkm_init_module(void){
	int counter;
	//for constructing a pid data structure out of integer pid
	struct pid* p1;
	struct pid* p2;
	//for retreiving task struct from pid
	struct task_struct* task1;
	struct task_Struct* task2;

	p1 = find_get_pid(first_pid);
	p2 = find_get_pid(second_pid);

	task1 = pid_task(p1, PIDTYPE_PID);
	task2 = pid_task(p2, PIDTYPE_PID);
	
	counter = 60;
	while(counter > 0){
		unsigned long usage1 = get_usage(task1);
		unsigned long usage2 = get_usage(task2);
		printk(KERN_INFO"[dbg] First cgroup usage: %lu", usage1);
		printk(KERN_INFO"[dbg] second cgroup usage: %lu", usage2);
		counter--;	
	}
	return 0;
}

static void __exit lkm_cleanup_module(void){
	printk(KERN_INFO"[dbg] Kernel modeul removed!");
}

//Registering the module
module_init(lkm_init_module);
modul_exit(lkm_cleanup_module);
