#include <stdio.h>

#define CODE 0b1100010

int main(int argc, char *argv[])
{
	int i = CODE;
	int j = CODE*2;
	char c = CODE;
	char *s = "abcdef";
	char *ch = s;
	int a = 'b';

	printf("the value of int is: %d\n", i);
	printf("the value of int*2 is: %d\n", j);
	printf("the value of char is: %c\n", c);
	printf("the value of a is: %d\n", a);
	printf("the value of s[3] is: %c\n", s[3]);
	printf("the address of s is   : %p\n", (void *)&s);
	printf("the address of s[0] is: %p\n", (void *)s[0]);
	
	printf("the value of ch[1] is: %c\n", ch[0]);
	printf("the address of ch is   : %p\n", (void *)&ch);
}
