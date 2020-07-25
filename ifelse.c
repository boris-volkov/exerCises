#include <stdio.h>

int main(int argc, char *argv[])
{

	if (argc == 1) {
		printf("you have one argument, you suck.\n");
	} else if (argc > 1 && argc < 4) {
		printf("Here's your arguments:\n");

		for (int i = 1; i < argc; i++){
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("you have too many arguments, you suck.\n");
	}

	return 0;
}

		
	
