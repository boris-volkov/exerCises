#include <stdio.h>

struct Problem{
	int a;
	int b;
	int c;
	int avg_time;
};


void populate_list(long unsigned int addr)
{
	long unsigned int pointer = addr;
	int i;
	int j;
	for(i = 0; i < 10; i++){
		for(j = 0; j < i; j++){
			*pointer = i;
			pointer += 4;
			*pointer = j;
			pointer += 4;
			*pointer = i*j;		
			pointer += 4;
		}
	}
}

int main()
{
	problem_list = (Problem *)malloc(50*3*sizeof(int);
	populate_list(problem_list);
	long unsigned int pointer = &problem_list;
	for(int i = 0; i < 10; i ++){
		printf("%d\n", *(int *)pointer);		
	}

}
