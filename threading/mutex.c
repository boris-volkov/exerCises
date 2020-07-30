// a MUTEX is a binary semaphore, only letting one thread into the 
// critical section at one time. 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //POSIX standard threading library.

pthread_mutex_t mtx;

// thread body functions need to have this signature. 
void* thread_body_1(void* arg){
	int* shared_var_ptr = (int*)arg;
	
	/* CRITICAL SECTION */
	pthread_mutex_lock(&mtx);
	(*shared_var_ptr)++;
	printf("%d\n", *shared_var_ptr);
	pthread_mutex_unlock(&mtx);
	/********************/

	return NULL;
}

void* thread_body_2(void* arg){
	int* shared_var_ptr = (int*)arg;
	
	/* CRITICAL SECTION */
	pthread_mutex_lock(&mtx);
	*shared_var_ptr += 2;
	printf("%d\n", *shared_var_ptr);
	pthread_mutex_unlock(&mtx);
	/********************/

	return NULL;
}

// when we reach pthread_mutex_lock, the function will wait until
// another thread unlocks the mutex before it can go into its 
// critical section. by default, this thread will go into sleeping
// mode if it finds the mutex locked, it does not go into busy-wait
// if you want it to busy-wait, make a pthread_spin_t object instead
// and use it in the same way. 

int main(){
	int shared_var = 0;

	//thread handlers
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&mtx, NULL);

	//create new threads
	//second parameter is about data space allocation for the thread, 
	//if left NULL, the thread is given the default data space. 
	int result1 = pthread_create(&thread1, NULL, thread_body_1, &shared_var);
	int result2 = pthread_create(&thread2, NULL, thread_body_2, &shared_var);

	if (result1 || result2){
		printf("The threads could not be created.\n");
		exit(1);
	}

	//wait for threads to finish
	result1 = pthread_join(thread1, NULL);
	result2 = pthread_join(thread2, NULL);

	if (result1 || result2){
		printf("The threads could not be joined.\n");
		exit(2);
	}

	pthread_mutex_destroy(&mtx);

	return 0;
}




	


