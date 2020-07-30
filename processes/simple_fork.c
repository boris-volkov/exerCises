#include <stdio.h>
#include <unistd.h>


int main() {
	int stack_variable = 7;
	printf("This is the parent process with process ID: %d\n", getpid());
	printf("Before calling fork() ... \n");
	pid_t ret = fork();

	// the child process inherits the terminal from the parent, as well 
	// as all open file descriptors at the time of the fork call.
	// the child has access to all the same memory, data, stack and heap.
	// call pstree -p to see the process tree and the parent/child relationships. 
	// the parent itself is a child of the bash process that called it. 

	// the call to fork returns 0 to the child process, and the PID to the 
	// parent process, this is how the next code can decide which process 
	// it belongs to.
	if (ret) {
		printf("My child process spawned with PID: %d\n", ret);
		printf("The address of my stack variable is %p\n", &stack_variable); 
	} else {
		printf("This is the child process with PID: %d\n", getpid());
		printf("The address of my stack variable is %p\n", &stack_variable);
	}

	printf("Ctrl+C to exit\n");
	while (1);
	return 0;
}

