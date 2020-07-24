#include <unistd.h> // sleep
#include <stdlib.h> // malloc
#include <stdio.h>

int main()
{
	void* ptr = malloc(1024); // 1KB on heap
	printf("address: %p\n", ptr);
	fflush(stdout); // forces print

	while (1) sleep(1);

	return 0;
}

