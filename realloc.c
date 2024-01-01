#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size=5;
    //for malloc
    int *p1=(int*)malloc(size*sizeof(int));
    for(int i=1;i<=size;i++)
    {
        printf("Enter number %d :",i);
        scanf("%d",&p1[i]);
    }
    printf("The initial numbers are: \n");
    for ( int i=1; i<= size; i++)
    {
        
        printf("The number %d is: %d\n", i,p1[i]);
    }
    

    size=3;
    p1=(int*)realloc(p1,size*sizeof(int));
    printf("The reallocated numbers are: \n");
     for ( int i=1; i <= size; i++)
    {
        
        printf("The number %d is: %d\n", i,p1[i]);
    }

free(p1);
}
