#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
	int fds[2];
	pipe(fds);
	/* pipe accepts an array of two ints and opens
	 * two file descriptors [0] for reading, [1] for writing
	 * each process closes the file descriptor that it is 
	 * not going to use. The pipe is unidirectional.
	 */

	int childpid = fork();
	if (childpid == -1) {
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	if (childpid == 0) {
		// child closes read file descriptor
		close(fds[0]);
		char str[] = "Hello Dad!";
		// child writes to write file descriptor
		fprintf(stdout, "Child waiting for 2 seconds... \n");
		sleep(2);
		fprintf(stdout, "Child writing to parent...\n");
		write(fds[1], str, strlen(str) + 1);
	} else {
		// parent closes write file descriptor
		close(fds[1]);
		char buff[32];
		// parent reads from read file descriptor
		fprintf(stdout, "Parent: reading from child... \n");
		int num_of_read_bytes = read(fds[0], buff, 32);
		fprintf(stdout, "Parent: received from child: %s\n", buff);
	}
	return 0;
}

