#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[10];
	int *pt = &arr[0];

	for (int i = 0; i < 10; i++){
		*pt = i;
		pt += 1;
		printf("|%d,%ld|\n in arr[%d]: %d\n", i, pt, arr[i],i);
	}
	
	printf("address of arr[9] is %ld\n", &arr[9]); 
	printf("pt is at %ld\n", pt);	
	printf("\n\nprinting array backwards\n");

	int *newpt = --pt;	
	for (int i = 0; i < 10; i++){
		printf("%d|", *newpt);
		newpt -= 2;       /* can step back out of bounds of array */
	}                         /* doesn't try to protect you  */
	printf("\n");
	
	char *pter;
	pter++;
	printf("does this work? %c\n", *pter);
	return 0;
}
