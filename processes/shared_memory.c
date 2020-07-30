#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>

#define SH_SIZE 16

int main() {
	// create a shared memory object with name "/shm0" with 16 bytes
	// this shared object remains even when the process quits. 
	// it is only destructed by rebooting or by getting unliked
	int shm_fd = shm_open("/shm0", O_CREAT | O_RDWR, 0600); // created for reading and writing
	if (shm_fd < 0) {
		fprintf(stderr, "ERROR: failed to create shared memory: %s\n", strerror(errno));
		return 1;
	}
	fprintf(stdout, "shared memory is created with fd: %d\n", shm_fd);



	// shared memory needs to be truncated to the appropriate size. 
	if (ftruncate(shm_fd, SH_SIZE * sizeof(char)) < 0) {
		fprintf(stderr, "ERROR: Truncation failed: %s\n", strerror(errno));
		return 1;
	}
	fprintf(stdout, "The memory region is truncated.\n");



	// mapping is used to map the shared memory to an address space that 
	// is accessible to the caller program. it is originally only in the 
	// kernel's memory space. 
	void* map = mmap(0, SH_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if (map == MAP_FAILED) {
		fprintf(stderr, "ERROR: Mapping failed: %s\n", strerror(errno));
		return 1;
	}

	char* ptr = (char*) map;
	ptr[0] = 'A';
	ptr[1] = 'B';
	ptr[2] = 'C';
	ptr[3] = '\n';
	ptr[4] = '\0';
	while(1);
	fprintf(stdout, "Data is written to the shared memory.\n");

	// unmap the memory
	if (munmap(ptr, SH_SIZE) < 0) {
		fprintf(stderr, "ERROR: Unmapping failed: %s\n", strerror(errno));
		return 1;
	}

	// close the file descriptor. 
	if (close(shm_fd) < 0) {
		fprintf(stderr, "ERROR: Closing shared memory failed: %s\n", strerror(errno));
		return 1;
	}
	return 0;
}
