// C program to show Nested Recursion

#include <stdio.h>
int fun(int n)
{
	if (n > 100)
		return n - 10;

	// A recursive function passing parameter
	// as a recursive call or recursion
	// inside the recursion
	return fun(fun(n + 11));
}

// Driver code
int main()
{
	int r;
	r = fun(95);
	printf("%d\n", r);
	return 0;
}
