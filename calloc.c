#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size=5;
    //for malloc
    int *p1=(int*)calloc(size, sizeof(int));
    printf("--The initial numbers are: \n");
    for(int i=1;i<=size;i++)
    {
        
        printf("The number %d is: %d\n", i,p1[i]);
    }



     for(int i=1;i<=size;i++)
    {
        printf("ENter the number %d: ",i);
        scanf("%d",&p1[i]);
        
    }
    printf("--After inputing value--\n");


    
    for ( int i=1; i <=size; i++)
    {
        printf("The number %d is: %d\n", i,p1[i]);
    }
    
    free(p1);
}
