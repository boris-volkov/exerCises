// the exec function is different from fork in that it 
// REPLACES the parent process. No new process is created, 
// only substitution of one for another. 
//
// here execvp is being used to start an echo process.
// execvp inherits the PATH environment variable, and searches
// for the executables there. Unlike fork, a process started with
// exec* does not inherit anything from the calling process. 
// exec* API can be used to run scripts and external executables, 
// while fork() creates a new process that is exactly the same
// C program that called it. 

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
	char* args[] = {"echo", "Hello", "World", 0 };
	
	execvp("echo", args);
	// first argument is the name of executable to look for,
	// second is the argument pointer. 
	// if the previous call is successful, the next code will not
	// execute because this process has been REPLACED.
	// for this reason there can be no interleaving problems.
	printf("execvp() failed. Error: %s\n", strerror(errno));
	return 0;
}

