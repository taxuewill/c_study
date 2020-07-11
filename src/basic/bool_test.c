#include <stdio.h>


int main(){
    printf("C if bool test\n");
    char c;
    c = getchar();
    printf("char is %c\n",c);
    int number = c-48;//0 is 48
    if(number){
        printf("this is true\n");
    }else{
        printf("this is false\n");
    }

    if(-1){
        printf("-1 is true\n");
    }
    

    return 0;
}