// C program to show Tree Recursion

#include <stdio.h>

// Recursive function
void fun(int n)
{
	if (n > 0) {
		printf("%d ", n);

		// Calling once
		fun(n - 1);

		// Calling twice
		fun(n - 1);
	}
}

// Driver code
int main()
{
	fun(3);
	return 0;
}
