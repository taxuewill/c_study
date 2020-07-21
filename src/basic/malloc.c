#include <stdio.h>  //printf, scanf, NULL
#include <stdlib.h> /* malloc, free, rand, system */

int main(int argc,void * argv[]){
    printf("Hello,%s with argc %d\n",argv[0],argc);
    int* variable;
    variable =(int *) malloc(sizeof(int));
    *variable = 15;

    printf("variable is %d\n",*variable);
    free(variable);


    return 0;
}