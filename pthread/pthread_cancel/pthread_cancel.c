#include <func.h>

void* threadFunc(void* p){
    
    printf("I am child thread\n");
    return NULL;
}

int main(int argc,char* argv[])
{
    pthread_t pthid;
    printf("pthid %ld\n",pthid);
    int ret;
    ret = pthread_create(&pthid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    
    ret = pthread_cancel(pthid);  //正常返回0  如果一个线程被cancel  join拿到的是-1
    THREAD_ERROR_CHECK(ret,"pthread_cancel");

    long threadRet;
    ret = pthread_join(pthid,(void**)&threadRet);
    THREAD_ERROR_CHECK(ret,"pthread_join");

    printf("I am main thread %ld\n",threadRet);
    return 0;
}
