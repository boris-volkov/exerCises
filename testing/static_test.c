#include <stdio.h>

int test(){
	static int i = 0;
	i++;
	return i;
}


int main() {
	for (int i = 0; i < 10; i++)
		fprintf(stdout, "%d ", test());
	return 0;
}


