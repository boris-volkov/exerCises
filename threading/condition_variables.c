// The goal of this program is to print "A" in one thread, 
// and then "B" in another thread, in that order, using
// condition variables for synchronization.
// a condition must be used together with a mutex.
// threads can wait on a condition, or also signal other
// threads that are waiting on it. 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int bool_t;


// since we can only pass a single pointer to each thread, 
// its good to pack every relevant thing into a struct.
typedef struct {
	bool_t done; // flag for "has A been printed yet?"
	pthread_mutex_t mtx; // for protecting critical section
	pthread_cond_t cv; // condition variable for synch
} shared_state_t;

void shared_state_init(shared_state_t* shared_state) {
	shared_state->done = FALSE;
	pthread_mutex_init(&shared_state->mtx, NULL);
	pthread_cond_init(&shared_state->cv, NULL);
}

void shared_state_destroy(shared_state_t* shared_state) {
	pthread_mutex_destroy(&shared_state->mtx);
	pthread_cond_destroy(&shared_state->cv);
}
// objects need initializers and destroyers!

void* thread_body_1(void* arg){
	shared_state_t* ss = (shared_state_t*)arg; //because it comes in as void
	
	/*CRITICAL SECTION*/
	pthread_mutex_lock(&ss->mtx);
	printf("A\n");
	ss->done = TRUE;
	pthread_cond_signal(&ss->cv); // signal to waiting threads
	pthread_mutex_unlock(&ss->mtx);
	/*******************/

	return NULL;
}

void* thread_body_2(void* arg) {
	shared_state_t* ss = (shared_state_t*) arg;

	/*CRITICAL SECTION*/
	pthread_mutex_lock(&ss->mtx);
	while (!ss->done){
		// wait on the condition variable
		// releases CPU to other threads,
		// associated mutex becomes released.
		pthread_cond_wait(&ss->cv, &ss->mtx);	
		// acquires lock after it is released from
		// wait but still needs to check if the done flag is TRUE
		// since it could have been signalled by something else
	}
	printf("B\n");
	pthread_mutex_unlock(&ss->mtx);
	/*note: pthread functions need to be sent addresses*/

	return NULL;
}

int main(){
	// shared state
	shared_state_t shared_state;
	shared_state_init(&shared_state);

	//thread handlers
	pthread_t thread1;
	pthread_t thread2;

	// create the threads
	int signal1 = pthread_create(&thread1, NULL, thread_body_1, &shared_state);
	int signal2 = pthread_create(&thread2, NULL, thread_body_2, &shared_state);

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

	// destroy shared state which also frees the 
	// mutex and conditional variable. 
	shared_state_destroy(&shared_state);

	return 0;
}






	





		
