#include <stdio.h>

int main(int argc, char *argv[])
{
	int height = 69;
	int size = sizeof(height);

	printf("I am %s years old.\n", argv[1]);
	printf("I am %d inches tall.\n", height);
	printf("The size of my height is %d.\n", size);

	return 0;
}
