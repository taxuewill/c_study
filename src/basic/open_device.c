#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>

#define DEVICE_NAME "/dev/test_dev2"

int main(void){
    printf("hello,device\n");
    
    int fd = -1;
    fd = open(DEVICE_NAME, O_RDWR);
    if(fd>0){
        printf("open dev success\n");
        
        if(ioctl(fd,5,NULL)>=0){
            printf("ioctl success\n");
        }
    }else{
        printf("open dev failed : %d\n",fd);
        perror("perror output:");
    }
}