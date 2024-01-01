#include <stdio.h>

int fibonacci(int);

int main(){
    int numbers, i;

    printf("How many numbers? ");
    scanf("%d", &numbers);

    printf("Fibonacci series:\n");

    for (i = 0; i < numbers; i++){
        printf("%d\t", fibonacci(i));
    }

    return 0;
}

int fibonacci(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}
