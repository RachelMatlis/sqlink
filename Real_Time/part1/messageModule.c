/*create a kernel module that allows for inter-process communication in Linux.*/

#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for class_create */
#include <linux/slab.h> /* for kmalloc, kfree */
#include <linux/cdev.h> /* for cdev_* */
#include <linux/sched.h> /* for TASK_INTERRUPTIBLE and more constants */
#include <linux/spinlock.h> /* for spinlock_t and ops on it */
#include <linux/wait.h> /* for wait_queue_head_t and ops on it */
#include <linux/uaccess.h> /* for copy_to_user, access_ok */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rachel and Margarita");
MODULE_DESCRIPTION("message queue module");
MODULE_VERSION("4.15.0");


/* this is the operations table */
static const struct file_operations queue_fops = {
	.owner = THIS_MODULE,
	//.open = 
	//.release = write_null,
};

/* this variable will store the class */
static struct class *my_class;
/* this variable will hold our cdev struct */
static struct cdev cdev;
/* this is the first dev_t allocated to us... */
static dev_t first_dev;
/* number of minors we need... */
static int mq_count = 8;
/* this is our first minor (0 by default)*/
static int first_minor;


struct my_mq_t {
	size_t size;
	size_t capacity;
	struct list_head list;
	struct device *mq_device; 
};

static struct my_mq_t* m_queues; 

static inline void m_queues_ctor(struct my_mq_t* m_queues)
{
	m_queues->size =0;
	m_queues->capacity=100;
	INIT_LIST_HEAD(&(m_queues->list));
	m_queues->mq_device = NULL;
}

static inline void m_queues_dtor(const struct my_mq_t *m_queue)
{

}

static int __init mq_init(void)
{
	int ret;
	int i;
	/* allocate all queues */
	m_queues = kmalloc(sizeof(struct my_mq_t)*mq_count, GFP_KERNEL);
	if (IS_ERR(m_queues)) 
	{
		pr_err("kmalloc\n");
		ret = PTR_ERR(m_queues);
		goto err_return;
	}
	/* initialize all m_queues */
	for (i = 0; i < mq_count; i++)
		m_queues_ctor(m_queues+i);
	/* allocate our own range of devices */
	ret = alloc_chrdev_region(&first_dev, first_minor, mq_count,THIS_MODULE->name);
	if (ret) 
	{
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_debug("allocated the region\n");
	/* add the cdev structure */
	cdev_init(&cdev, &queue_fops);
	ret = cdev_add(&cdev, first_dev, mq_count);
	if (ret) 
	{
		pr_err("cannot cdev_add\n");
		goto err_dealloc;
	}
	pr_debug("added the cdev\n");
	/* this is creating a new class (/proc/devices) */
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class)) 
	{
		pr_err("class_create\n");
		ret = PTR_ERR(my_class);
		goto err_cdev_del;
	}
	pr_debug("created the class\n");
	for (i = 0; i < mq_count; i++) 
	{
		/* and now lets auto-create a /dev/ node */
		m_queues[i].mq_device = device_create(my_class, NULL,
			MKDEV(MAJOR(first_dev), MINOR(first_dev)+i),
			NULL, "%s%d", THIS_MODULE->name, i);
		if (IS_ERR(m_queues[i].mq_device)) 
		{
			pr_err("device_create\n");
			ret = PTR_ERR(m_queues[i].mq_device);
			goto err_class;
		}
	}
	pr_info(KBUILD_MODNAME " loaded successfully\n");
	return 0;

err_class:
	class_destroy(my_class);
err_cdev_del:
	cdev_del(&cdev);
err_dealloc:
	unregister_chrdev_region(first_dev, mq_count);
err_final:
	for (i = 0; i < mq_count; i++)
		m_queues_dtor(m_queues+i);
	kfree(m_queues);
err_return:
	return ret;
}

static void __exit mq_exit(void)
{
	int i;
	for (i = 0; i < mq_count; i++)
		device_destroy(my_class, MKDEV(MAJOR(first_dev),
			MINOR(first_dev)+i));
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, mq_count);
	for (i = 0; i < mq_count; i++)
		m_queues_dtor(m_queues+i);
	kfree(m_queues);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}

module_init(mq_init);
module_exit(mq_exit);
