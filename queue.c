#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(rear==N-1){
        printf("Overflow");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if(rear==-1 && front==-1){
        printf("Underflow");
    }
    else if(rear==front){
        front=rear=-1;
    }
    else{
        printf("\nDequeued element is %d\n",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1){
        printf("No elements to display\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}
int main(){
    enqueue(9);
    enqueue(2);
    enqueue(5);
    enqueue(7);
    display();
    dequeue();
    display();

}