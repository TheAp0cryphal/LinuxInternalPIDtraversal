#include <stdio.h>
#include <string.h>
int main()
{
    FILE *proc = fopen("/proc/meminfo","r");

    if (proc == NULL)
    {
        perror("opendir(/proc)");
        return 1;
    }
    char c[256];
    long long int buff=0;
    long long int memTotal=0;
    long long int memFree=0;
    long long int memCached=0;
    long long int memSlabbed=0;
    while (fgets(c,256,proc)){
   //     printf("%s", c);
        int i=0;
        char res[30];
        int k=0;
        while(c[i]!=':'){
            res[i]=c[i];
            k++;
            i++;
        }
        res[i]=0;
        i++;
        while(c[i]==' '){
            i++;
        }
        long long int mem=0;
        while(c[i]>='0' && c[i]<='9'){
            mem=mem*10+(c[i]-'0');
            //printf("%c",c[i]);
            i++;
        }
        if(strcmp(res,"Buffers")==0){
            buff=mem;
        }
        if(strcmp(res,"MemTotal")==0){
            memTotal=mem;
        }
        if(strcmp(res,"MemFree")==0){
            memFree=mem;
        }
        if(strcmp(res,"Cached")==0){
            memCached=mem;
        }
        if(strcmp(res,"Slab")==0){
            memSlabbed=mem;
        }
    }   
    double memUtil=(memTotal-memFree-buff-memCached-memSlabbed)*100;
    memUtil=(double)memUtil/memTotal;
    printf("\n%.2f\n",memUtil);
   // printf("%lld %lld %lld %lld %lld",buff,memTotal,memFree,memCached,memSlabbed); 
    return 0;
}