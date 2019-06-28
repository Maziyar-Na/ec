#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/special_insns.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/proc_fs.h>
#include <linux/pid.h>
#include <linux/pid_namespace.h>
#include <linux/delay.h>
#include <linux/memcontrol.h>
#include <linux/init.h>
#pragma once

#define MODULE_NAME "total_mem_usage"
static int first_pid = 0;
static int second_pid = 0;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAZIYAR");

module_param(first_pid, int, 0);
module_param(second_pid, int, 0);

MODULE_PARM_DESC(first_pid, "first container monitored!");
MODULE_PARM_DESC(second_pid, "second container monitored!");
