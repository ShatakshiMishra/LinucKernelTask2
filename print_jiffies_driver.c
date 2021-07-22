#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>

#define RD_DATA _IOR('a','b',int32_t*)
int32_t val=0;
unsigned long js, je, tet;
int ex04_open(struct inode *pinode, struct file *pfile)
{
printk(KERN_ALERT "OPEN ");
return 0;
}
ssize_t ex04_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
printk(KERN_ALERT "READ");
return 0;
}
ssize_t ex04_write(struct file *pfile, const char __user *buffer,size_t length, loff_t *offset)
{
printk(KERN_ALERT "WRITTEN ");
return length;
}
int ex04_close(struct inode *pinode, struct file *pfile)
{

printk(KERN_ALERT "CLOSE ");
return 0;
}
static long ex04_ioctl(struct file *pfile, unsigned int cmd, unsigned long arg)
{ val=js;
 switch(cmd)
 {
       
         case RD_DATA:
                 {
                copy_to_user((int32_t*)arg,&val,sizeof(val));
                }
       break;
 }
return 0;
}
struct file_operations ex04_file_ops=
{
 
        .owner=THIS_MODULE,
        .open =ex04_open,
        .read =ex04_read,
        .write =ex04_write,
        .release =ex04_close,
        .unlocked_ioctl= ex04_ioctl,
};
static int simple_char_init(void)
{
        printk(KERN_INFO "LOAD");
        register_chrdev(205,"jiffies_driver",&ex04_file_ops);
 js = jiffies;
    printk("\n[Jiffies start Time : %lu]\nModule Started.\n", js);
        return 0;
}
static void simple_char_exit(void)
{
        printk(KERN_INFO "UNLOAD");
        unregister_chrdev(205,"jiffies_driver");
        tet = je - js;
    printk("\nEnd Time [%lu] - Start Time [%lu]: \nTotlal elapsed Time [%lu]\n",js,je, tet);
}
module_init(simple_char_init);
module_exit(simple_char_exit);






