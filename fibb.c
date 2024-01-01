#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("Error: Fibonacci is not defined for negative numbers.\n");
    } else {
        int result = fibonacci(num);
        printf("Fibonacci of %d is %d\n", num, result);
    }

    return 0;
}
