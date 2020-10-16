#include <func.h>

void* threadFunc(void* p){
    printf("I am child thread %d\n",*(int*)p);
    for(int i=0;i<5;i++){
        printf("awdsi=%d\n",i);
    }

}

int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    int pArg=10;
    ret = pthread_create(&pthid,NULL,threadFunc,&pArg);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    sleep(2);
    printf("sleep over\n");
    pthread_join(pthid,NULL);
    printf("I am main thread\n");
    return 0;
}

