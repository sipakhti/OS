#include<stdio.h>
#include<stdlib.h>
struct human 
{
    int a;
    char b;
};

void print(struct human obj)
{
    printf("%d %c\n",obj.a,obj.b);
}

int main(int argc, char*argv)
{
    //struct object runtime
    struct human *obj =(struct human*)  malloc(10* sizeof(struct human));
    // initialize integer array

    obj[0].a = 200;
    obj[0].b = 'z';
    print(obj[0]);
 /*   int a;
    float p=10;
    char c ='c';
    printf("Enter the first value=");
    scanf("%d",&a);

    printf("Hell OS\n");
    printf("int value = %d %f %c\n",a,p,c);
    if(a<=30)
    {
        printf("Fail\n");
    }
    else
    {
        printf("pass\n");
    }
    int* p = (int*) malloc(10*sizeof(int));
}
*/
    // deallocate the memory
    free(obj);
    return 0;
}