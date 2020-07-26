#include <stdio.h>

int main(int argc, char *argv[])
{
	char *from = "abcde";
	char *to = "zyxwv";
	printf("value of to is %s\n", to);
	printf("value of *to is %d\n", *to);
	printf("value of *from is %d\n", *from);
	printf("value of *++to is %d\n", *++to);
	printf("value of to[3] is %d\n", to[3]);
}
