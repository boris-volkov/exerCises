#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n)
{
	if (n < 1) return 1;
	return n * factorial(n-1);
}

int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	int b = factorial(a);
	printf("%d factorial is %d\n", a, b);

}


