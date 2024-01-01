// #include <stdio.h>
// int main()
// {
//   int array[100], search, c, n;

//   printf("Enter number of elements in array\n");
//   scanf("%d", &n);

//   printf("Enter %d integer(s)\n", n);

//   for (c = 0; c < n; c++)
//     scanf("%d", &array[c]);

//   printf("Enter a number to search\n");
//   scanf("%d", &search);

//   for (c = 0; c < n; c++)
//   {
//     if (array[c] == search)    /* If required element is found */
//     {
//       printf("%d is present at location %d.\n", search, c);
//       break;
//     }
//   }
//   if (c == n)
//     printf("%d isn't present in the array.\n", search);

//   return 0;
// }


// #include<stdio.h>
// int main(){
//   int arr[100];
//   int i,n,data;
//   printf("Enter the no of element");
//   scanf("%d",&n);
//   printf("Enter elements:");
//   for(i=0;i<n;i++)
//   scanf("%d",&arr[i]);
//   printf("Enter data to be searched");
//   scanf("%d",&data);
//   for(i=0;i<n;i++){
//     if(data==arr[i]){
//     printf("Element found at index %d",i);
//      break;
//     }
//   }
// if(i==n){  
// printf("Sorry");
// }
// }

// #include <stdio.h>

// int main() {
//     int arr[] = {1, 3, 5, 6, 8, 9, 12, 15, 14};
//     int l = 0;
//     int r = 8;
//     int mid, n;
    
//     printf("Enter the element to be searched: ");
//     scanf("%d", &n);
    
//     while (l <= r) {
//         mid = (l + r) / 2;
        
//         if (n == arr[mid]) {
//             printf("Element found at index %d", mid);
//             return 0; // Exit the program as the element is found
//         } else if (n < arr[mid]) {
//             r = mid - 1;
//         } else {
//             l = mid + 1;
//         }
//     }
    
//     printf("Element not found\n");
//     return 0;
// }

// #include<stdio.h>
// #define N 5
// int stack[N];
// int top=-1;
// void push(int x){
//     if(top==N-1){
//         printf("Overflow");
//     }
//     else{
//         top=top+1;
//         stack[top]=x;
//     }
// }
// void pop(){
//     if(top==-1){
//         printf("Underflow");
//     }
//     else{
//         printf("Popped item is %d",stack[top]);
//         top--;
//     }
// }
// void display(){
//     if(top==-1){
//         printf("No data");
//     }
//     else{
//         int i;
//         for(i=0;i<=top;i++){
//             printf("%d",stack[i]);
//         }
//     }
// }
// int main(){
//     push(5);
//     push(8);
//     push(16);
//     push(0);
//     push(3);
//     display();
//     push(33);
// }

#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(rear==N-1){
        printf("Overflow");
    }
    else if(rear==-1 && front==-1){
        front=0;
        rear=0;
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
        printf("\nDequeued element is %d",queue[front]);
        front++;
    }
}
void display(){
    int i;
    if(rear==-1 && front==-1){
        printf("no element");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("\n%d",queue[i]);
        }
    }
}
int main(){
    enqueue(9);
    enqueue(4);
    enqueue(1);
    display();
    dequeue();
    display();
}
