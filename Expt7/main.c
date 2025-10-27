#include <stdio.h>
#include <time.h>

int fun1()
{
    for(int i=0;i<5;i++)
    {
        printf("Hello World\n");
    }
    return 0;
}

int fun2()
{
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    printf("Hello World\n");
    return 0;
}

int main()
{
    clock_t t1,t2;
    t1=clock();
    fun1();
    t1=clock()-t1;
    double tt1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("Time taken by fun1: %f\n",tt1);

    t2=clock();
    fun2();
    t2=clock()-t2;
    double tt2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("Time taken by fun1: %f\n",tt2);
    
    return 0;
}