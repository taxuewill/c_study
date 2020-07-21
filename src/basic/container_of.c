#include <stdio.h>
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({                                  \
                    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
                    (type *)( (char *)__mptr - offsetof(type,member) ); })
struct test_struct
{
    int num;
    char ch;
    float f1;
};

int main(int argc, void *argv[])
{
    printf("Hello,%s with argc %d\n", argv[0], argc);
    struct test_struct *pTestStruct;
    struct test_struct init_struct = {1, 'a', 12.3f};
    char *ptr_ch = &init_struct.ch;
    pTestStruct = container_of(ptr_ch, struct test_struct, ch);
    printf("pTestStruct->num = %d\n", pTestStruct->num);
    printf("pTestStruct->ch = %c\n", pTestStruct->ch);
    printf("pTestStruct->f1 = %.2f\n", pTestStruct->f1);
    return 0;
}