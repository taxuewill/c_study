#include <stdio.h>

enum{
    SVC_MGR_GET_SERVICE = 1,
    SVC_MGR_CHECK_SERVICE,
    SVC_MGR_ADD_SERVICE,
    SVC_MGR_LIST_SERVICES,
};

int main(void){

    printf("Hello,C\n");
    printf("SVC_MGR_GET_SERVICE %d\n",SVC_MGR_GET_SERVICE);
    printf("SVC_MGR_CHECK_SERVICE %d\n",SVC_MGR_CHECK_SERVICE);
    printf("SVC_MGR_ADD_SERVICE %d\n",SVC_MGR_ADD_SERVICE);
    printf("SVC_MGR_LIST_SERVICES %d\n",SVC_MGR_LIST_SERVICES);
    return 0;
}