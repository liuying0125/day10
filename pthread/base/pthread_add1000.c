#include <func.h>
#define N 20000000
void* threadFunc(void* p){
    int i;
    for(i=0;i<N;i++){
        *(int*)p+=1;
    }
}


int main(int argc,char* argv[])
{
    pthread_t pthid;
    int ret;
    int val = 0;
    ret = pthread_create(&pthid,NULL,threadFunc,&val);
    THREAD_ERROR_CHECK(ret,"pthread_create");
    int i;
    for(i=0;i<N;i++){
        val+=1;
    }
    pthread_join(pthid,NULL);
    printf("I am main thread %d\n",val);
    return 0;
}

