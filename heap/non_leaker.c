#include <stdlib.h>

int main()
{
	char* ptr = (char*)malloc(16 * sizeof(char));
	free(ptr);
	return 0;

}

