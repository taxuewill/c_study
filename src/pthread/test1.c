#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

static pthread_key_t key;

struct test_struct{
    int i;
    float k;
};

void * child1(void* arg){
    struct test_struct struct_data;
    struct_data.i = 10;
    struct_data.k = 3.14;
    pthread_setspecific(key, & struct_data);
    printf ("struct_data addr %p\n", &(struct_data));
    printf ("child1  pthread_getspecific(key)返回的指针为:%p\n", (struct test_struct *)pthread_getspecific(key));
    printf ("利用 pthread_getspecific(key)打印 child1 线程中与key关联的结构体中成员值:\nstruct_data.i:%d\nstruct_data.k: %f\n", ((struct test_struct *)pthread_getspecific (key))->i, ((struct test_struct *)pthread_getspecific(key))->k);
    printf ("------------------------------------------------------\n");
}

void *child2 (void *arg)
{
    int temp = 20;
    sleep (2);
    printf ("child2 中变量 temp 的地址为 0x%p\n",  &temp);
    pthread_setspecific (key, &temp);
    printf ("child2 中 pthread_getspecific(key)返回的指针为:0x%p\n", (int *)pthread_getspecific(key));
    printf ("利用 pthread_getspecific(key)打印 child2 线程中与key关联的整型变量temp 值:%d\n", *((int *)pthread_getspecific(key)));
}

int main(void){

    printf("Hello,C\n");

    pthread_t tid1,tid2;
    pthread_key_create(&key,NULL);
    pthread_create(&tid1,NULL,(void *)child1,NULL);
    pthread_create(&tid2,NULL,(void*)child2,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_key_delete (key);
    
    return 0;
}