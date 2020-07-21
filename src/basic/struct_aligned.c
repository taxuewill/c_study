
#include <stdio.h>
#include <linux/stddef.h>

struct rb_node
{
    /* data */
    unsigned long  __rb_parent_color;
    struct rb_node * rb_right;
    struct rb_node * rb_left;
} __attribute__((aligned(sizeof(long))));


#define	rb_entry(ptr, type, member) container_of(ptr, type, member)

int main(void){

    printf("size of unsigned long is %ld\n",sizeof(unsigned long));
    printf("size of long is %ld\n",sizeof(long));
    printf("size is %ld\n",sizeof(struct rb_node));
    
    
    return 0;
}