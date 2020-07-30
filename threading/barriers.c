// a barrier is a simpler way to do what was done with 
// the condition variable and mutex. POSIX systemd dont
// actually provide a "barrier", but instead this is 
// internally implemented with a mutex and cond var. 
// barriers are easier to write but they make code less
// portable. OSX does not have barriers. 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_barrier_t barrier;

void* thread_body_1(void* arg){
	printf("A\n");
	pthread_barrier_wait(&barrier);
	return NULL;
}

void* thread_body_2(void* arg) {
	pthread_barrier_wait(&barrier); 
	//released when there are 2 threads waiting
	printf("B\n");
	return NULL;
}

int main(){

	// initialize barrier
	pthread_barrier_init(&barrier, NULL, 2);
	// 2 is the number of threads that we want
	// waiting on this barrier until they are released 

	//thread handlers
	pthread_t thread1;
	pthread_t thread2;

	// create the threads
	int signal1 = pthread_create(&thread1, NULL, thread_body_1, NULL);
	int signal2 = pthread_create(&thread2, NULL, thread_body_2, NULL);

	if (signal1 || signal2){
		printf("the threads could not be created");
		exit(1);
	}

	// wait for threads to finish
	signal1 = pthread_join(thread1, NULL);
	signal2 = pthread_join(thread2, NULL);

	if (signal1 || signal2){
		printf("the threads could not be joined");
		exit(2);
	}
	
	pthread_barrier_destroy(&barrier);

	return 0;
}






	





		
