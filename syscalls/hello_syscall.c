#define _GNU_SOURCE

#include <unistd.h>

#include <sys/syscall.h>

int main(){
	char message[20] = "Hello World!\n";
	// invoke write system call that 
	// writes bites int stdout
	
	syscall(__NR_write, 1, message, 13);
	return 0;
}

