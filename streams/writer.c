#include <stdio.h>

int main(){

	FILE *target = fopen("new_name", "w");
	fprintf(target, "hello world\n");
	fclose("new_name");

}


