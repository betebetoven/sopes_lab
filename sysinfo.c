#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/sched/signal.h> // Required for iterating over tasks
//LA TAREA SE TRABAJÓ EN RASPBERRY PI DEBIDO A QUE MI COMPUTADORA TAMBIEN LA UTILIZO PARA 
//TRABAJAR Y NO QUERIA QUE SE DAÑARA, YA QUE AL INSTALAR EL MODULO EN LA PARTICION FISICA DE LINUX EN MI COMPUTADORA
//ESTA PEDIA REALIZAR CAMBIOS QUE PODIAN DAÑAR AMBAS PARCICIONES, POR LO QUE DECIDI HACERLO EN RASPBERRY PI
// YA QUE CUENTA CON LINUX Y FUNCIONA EXACTAMENTE IGUAL QUE EN MI COMPUTADORA
//PARA COMPILAR EL MODULO SE UTILIZO EL COMANDO MAKE, Y PARA INSTALARLO SE UTILIZO EL COMANDO INSMOD sysinfo.ko
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Module to display memory and process information");
MODULE_VERSION("1.0");

#define PROC_NAME "sysinfo"

static int sysinfo_show(struct seq_file *m, void *v) {
    struct sysinfo si;
    struct task_struct *task;
    struct task_struct *child;
    struct list_head *list;

    si_meminfo(&si);

    seq_printf(m, "Total RAM: %lu KB\n", si.totalram * 4);
    seq_printf(m, "Free RAM: %lu KB\n", si.freeram * 4);
    seq_printf(m, "Shared RAM: %lu KB\n", si.sharedram * 4);
    seq_printf(m, "Buffer RAM: %lu KB\n", si.bufferram * 4);
    seq_printf(m, "Total Swap: %lu KB\n", si.totalswap * 4);
    seq_printf(m, "Free Swap: %lu KB\n", si.freeswap * 4);

    seq_printf(m, "Number of processes: %d\n", num_online_cpus());

    // Iterate over each task (process)
    for_each_process(task) {
        // Print parent process information
        seq_printf(m, "\nParent Process: %s [PID: %d]\n", task->comm, task->pid);

        // Iterate over each child of the current task
        list_for_each(list, &task->children) {
            child = list_entry(list, struct task_struct, sibling);
            seq_printf(m, "  Child Process: %s [PID: %d]\n", child->comm, child->pid);
        }
    }

    return 0;
};

static int sysinfo_open(struct inode *inode, struct file *file) {
    return single_open(file, sysinfo_show, NULL);
}

static const struct proc_ops sysinfo_ops = {
    .proc_open = sysinfo_open,
    .proc_read = seq_read,
};

static int __init sysinfo_init(void) {
    proc_create(PROC_NAME, 0, NULL, &sysinfo_ops);
    printk(KERN_INFO "sysinfo module loaded\n");
    return 0;
}

static void __exit sysinfo_exit(void) {
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "sysinfo module unloaded\n");
}

module_init(sysinfo_init);
module_exit(sysinfo_exit);
