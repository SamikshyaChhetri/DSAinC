// #include <stdio.h>

//  int factorial(int n);

// int main() {
//     int n;
//     printf("Enter a positive integer: ");
//     scanf("%d", &n);
//     printf("Factorial of %d = %d", n, factorial(n));
//     return 0;
// }

//  int factorial(int n) {
//     if (n == 0) {
//         return 1;
//     } else {
//         return n * factorial(n - 1);
//     }
// }

#include <stdio.h>

void headRecursion(int n) {
    if (n > 0) {
        headRecursion(n - 1); // Recursive call before any other code
        printf("%d ", n);
    }
}

int main() {
    int num = 5;
    printf("Head Recursion: ");
    headRecursion(num);
    return 0;
}
