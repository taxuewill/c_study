#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<asm/io.h>
#include<linux/cdev.h>

MODULE_LICENSE("GPL");

#define DEVICE_NAME "test_dev2"


static int __init test_init(void);
static void __exit test_exit(void);
static int test_open(struct inode *inode,struct file *file);
static long test_ioctl(struct file *file,unsigned int cmd,unsigned long arg);


static int alloc_dev_num;
static dev_t num_dev;
struct cdev dev_c;
struct class *cdev_class;

static struct file_operations led_fops={
    .owner=THIS_MODULE,
    .open=test_open,
    .unlocked_ioctl=test_ioctl,
    //.ioctl=led_ioctl;
};


static int test_open(struct inode *inode,struct file *file)
{
    printk("test__open");
    return 0;
}

static long test_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
    printk("test_ioctl cmd=[%d]",cmd);
    return 0;
}

static int __init test_init(void)
{
    int ret;
    ret=alloc_chrdev_region(&num_dev,0,1,DEVICE_NAME);
    alloc_dev_num=MAJOR(num_dev);
    printk("alloc dev num=[%d] ret=[%d]\n",alloc_dev_num,ret);
    cdev_init(&dev_c,&led_fops);
    printk("cdev_init!");
    ret=cdev_add(&dev_c,num_dev,1);
    printk("cdev_add ret=[%d]",ret);
    cdev_class=class_create(THIS_MODULE,DEVICE_NAME);
    if(IS_ERR(cdev_class))
    {
        printk("class_create error!");
    }
    printk("class_create success!");
    device_create(cdev_class,NULL,num_dev,0,DEVICE_NAME);
    printk("end...");
    return ret;
}

static void __exit test_exit(void)
{
    printk("test_exit");
    device_destroy(cdev_class,num_dev);
    class_destroy(cdev_class);
    cdev_del(&dev_c);
    unregister_chrdev_region(num_dev,1);
}

module_init(test_init);
module_exit(test_exit);

/*

#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<asm/io.h>
#include<linux/cdev.h>

MODULE_LICENSE("GPL");

#define DEVICE_NAME "test_dev1"

static unsigned int major_dev;

static int __init test_init(void);
static void __exit test_exit(void);
static int test_open(struct inode *inode,struct file *file);
static long test_ioctl(struct file *file,unsigned int cmd,unsigned long arg);


static int alloc_dev_num;
static dev_t num_dev;
struct cdev dev_c;
struct class *cdev_class;

static struct file_operations led_fops={
    .owner=THIS_MODULE,
    .open=test_open,
    .unlocked_ioctl=test_ioctl,
    //.ioctl=led_ioctl;
};


static int test_open(struct inode *inode,struct file *file)
{
    printk("test__open");
    return 0;
}

static long test_ioctl(struct file *file,unsigned int cmd,unsigned long arg)
{
    printk("test_ioctl cmd=[%d]",cmd);
    return 0;
}

static int __init test_init(void)
{
    int ret=0;
    ret=register_chrdev(0,DEVICE_NAME,&led_fops);//成功是返回值即为设备号
    if(ret<0)
    {
        printk("led cannot reg magor num :[%d] ret=[%d]",ret,ret);
        return ret;
    }
    printk("led reg magor num success [%d]",ret);
	major_dev=ret;
    return ret;
}

static void __exit test_exit(void)
{
    unregister_chrdev(major_dev,DEVICE_NAME);
    printk("led unreg magor num :[%d] success",major_dev);
}

module_init(test_init);
module_exit(test_exit);

*/