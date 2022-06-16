#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int* arr;
int key =5;
struct info
{
    int start;
    int end;
};
void* search(void* argc)
{
    struct info * p = (struct info*) argc;
    for(int i=p->start;i<p->end;i++)
    {
        if(arr[i]==key)
        {
            printf("Found\n");
        }
    }
    pthread_exit(NULL);
}
int main()
{
    arr = (int*) malloc(10000*sizeof(int));
    for(int i=0;i<10000;i++)
    {
        arr[i] = rand()%10+1;
    }
    struct info s[10];
    s[0].start=0;
    s[0].end=999;
    for(int i=1;i<10;i++)
    {
        s[i].start =  s[i-1].end+1;        
        s[i].end = s[i-1].end+1000;
    }
    pthread_t id[10];
    for(int i=0;i<10;i++)
        pthread_create(&id[i],NULL,&search,(void*)&s[i]);
    
}


