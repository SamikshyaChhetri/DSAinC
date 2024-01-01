//program to create and push to a stack
#include <stdio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push() {
    int x;
    printf("Enter data:");
    scanf("%d",&x);
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        top++;
        stack[top]=x;
    }
}
void pop(){
    int item;
    if(top==-1){
        printf("Stack is underflow");
    }
    else
    {
        item=stack[top];
        top--;
        printf("\n%d is popped\n",item);
    }
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d\t",stack[i]);
    }
}
int main() {
    push();
    push();
    push();
    push();
    display();
    pop();
    pop();
    display();

    return 0;
}
