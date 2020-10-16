#include <func.h>

void* threadFunc(void* p){
    printf("I am child thread %ld\n",*(long*)p);

}

long pArg=4;

int main(int argc,char* argv[])
{
    pthread_t pthid,pthid1;
    int ret;
    pArg=10;
    ret = pthread_create(&pthid,NULL,threadFunc,&pArg);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    pArg=2;
    ret = pthread_create(&pthid1,NULL,threadFunc,(void*)pArg);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    pArg=55;
    pthread_join(pthid,NULL);
    pthread_join(pthid1,NULL);
    printf("I am main thread\n");
    return 0;
}

