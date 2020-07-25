#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int t = time(0);
	printf("the time is %d.\n", t);
	int seed = atoi(argv[1]);
	printf("the seed entered was %d.\n", seed);
	srand(seed);
	int b = rand();
	printf("the random number is %d.\n", b);
	printf("\a");
	return 0;

}

