#include <stdio.h>

int main(){
	FILE* file = fopen("new_name", "r");
	char read;
	while((read = fgetc(file)) != EOF)
		fprintf(stdout, "%c", read);
	fclose(file);
	return 0;
}
