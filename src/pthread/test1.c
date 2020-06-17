#include <stdio.h>
#include <pthread.h>

int main(void){

    printf("Hello,C\n");

    pthread_key_t gTLS = 0;
    int result = pthread_key_create(&gTLS,NULL);
    if(result==0){
        printf("create key success\n");
    }
    printf("result is %d\n",result);
    return 0;
}