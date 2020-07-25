#include <stdio.h>

int main(int argc, char *argv[])
{
	int ages[] = { 29, 30, 31, 25 };
	char *names[] = {
		"Dallas", "Tim",
		"Boris", "Sian"
	};

	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//first way using indexing
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
				names[i], ages[i]);
	}

	printf("---\n");

	//set up pointers to the start of array
	int *cur_age = ages;
	char **cur_name = names;

	//second way using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
		*(cur_name + i), *(cur_age + i));
	}

	printf("---\n");

	//third way, pointers are just arrays
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n",
				cur_name[i], cur_age[i]);
	}
	
	printf("---\n");

	//fourth way with pointers in a stupid complex way
	for (cur_name = names, cur_age = ages;
			(cur_age - ages) < count; 
			cur_name++, cur_age++) {
		printf("%s is from the %dth dimension.\n", 
				*cur_name, *cur_age);
	}

	return 0;
}

