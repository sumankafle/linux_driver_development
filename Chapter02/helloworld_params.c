#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

static char *mystr = "hello";
static int myint = 1;
static int myarr[3] = {0,1,2};


module_param(myint, int, S_IRUGO);
module_param(mystr, charp, S_IRUGO);
module_param_array(myarr, int, NULL, S_IRUGO);

MODULE_PARM_DESC(myint, "An integer");
MODULE_PARM_DESC(mystr, "A character string");
MODULE_PARM_DESC(myarr, "An array of integers");
MODULE_INFO(my_field_name, "my_field_value");

static int __init helloworld_init(void){
    pr_info("Hello Worls!\n");
    pr_info("Name: %s\n", mystr);
    pr_info("Integer value: %d\n", myint);
    pr_info("Array values: %d, %d, %d\n", myarr[0], myarr[1], myarr[2]);
    return 0;
}

static void __exit helloworld_exit(void) {
    pr_info("End of the world\n");
}
module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Suman");
MODULE_DESCRIPTION("A simple Hello World Kernel Module with parameters");
MODULE_VERSION("1.0");
