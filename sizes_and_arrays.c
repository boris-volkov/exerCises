#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = { 10, 12, 13, 14, 20 };
	char name[] = "boris";
	char full_name[] = { 'b', 'o', 'r', 'i', 's', ' ', 'v'};

	// on some systems this will have to change %ld to %u since it will use unsigned
	printf("the size of an int: %ld \n", sizeof(int)); 
	printf("the size of areas (int[]): %ld \n", sizeof(areas));
	printf("the number of ints in areas: %ld \n",
			sizeof(areas) / sizeof(int));
	printf("the first area is %d, and 2nd %d \n", areas[0], areas[1]);

	printf("the size of char is %ld \n", sizeof(char));
	printf("the size of name (char[]): %ld \n", sizeof(name));
	printf("the number of chars: %ld \n", sizeof(name) / sizeof(char));

	printf("the size of full_name (char[]) :%ld \n", sizeof(full_name));
	printf("the number of chars: %ld \n", sizeof(full_name) / sizeof(char));

	printf("name = \"%s\" and full_name = \"%s\"\n", name, full_name); 


	return 0;
}
