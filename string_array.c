#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;

	argv[2] = "changed";
	for (i = 0; i < argc; i++) {
		printf("arg %d: %s \n", i, argv[i]);
	}

	//make an array of strings
	char *states[] = {
		"california", "oregon", 
		"washington", "texas", NULL, argv[3]
	};

	int num_states = 6;

	for (i = 0; i < num_states; i++) {
		printf("state %d: %s \n", i, states[i]);
	}

	return 0;
}
