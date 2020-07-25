#include <stdio.h>

int main()
{
	char array[4] = { 0b1000001, 0b1000010, 0b1000011, 0b1000100 };
	long unsigned int pointer; 
	pointer = &array; 	  
	for(int i = 0; i < 4; i++){
		printf("item at address %ld is %c\n",
				pointer, * ( (char * ) pointer )); 
		pointer += sizeof(char); 
	}				
}
