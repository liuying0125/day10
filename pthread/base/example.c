#include <func.h>
void *ThreadFunc(void* pArg){
    int iArg = (int)pArg;//将void*转换为int
    sleep(iArg);
    if(iArg<3)
        return (void*)(iArg*2);
    else
        pthread_exit((void*)(iArg*2));

}

int main(int argc,char* argv[])
{
    pthread_t thdId;
    int iRet=0;
    pthread_create(&thdId,NULL,ThreadFunc,(void*)2);
    pthread_join(thdId,(void**)&iRet);
    printf("The first child thread ret is:%d\n",iRet);
    pthread_create(&thdId,NULL,ThreadFunc,(void*)4);
    pthread_join(thdId,(void**)iRet);
    printf("The second child thread ret is: %d\n",iRet);
    return 0;
}

