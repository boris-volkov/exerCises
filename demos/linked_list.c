#include <stdio.h>
#include <limits.h>

struct Node{
	int val;
	struct Node* next;
};

int main(){
	struct Node x, y;
	x.val = 0xabcdef9;
	y.val = 0x1101101;
	y.next = NULL;
	x.next = &y;
	printf("size of node is %lu\n", sizeof(x));
	printf("size of data is %lu\n", sizeof(x.val));
	printf("size of ptr is %lu\n", sizeof(x.next));
	printf("int is %x \n", x.val);
	printf("address of y is %p\n", x.next);
	printf("relative addres of data is %lx,\n", ((long unsigned int)&x.val - (long unsigned int) &x));
	printf("relative addres of pointer is %lx,\n", ((long unsigned int)&x.next - (long unsigned int) &x));
	printf("distance between two nodes %lx,\n", (long unsigned int)&y - (long unsigned int)&x);

	unsigned char* byte = (unsigned char*) &x;
	for (int i = 0; i < sizeof(x); i++, byte++){
		printf("%x ", *byte);
	}

	printf("\n");
	return 0;
}

	
