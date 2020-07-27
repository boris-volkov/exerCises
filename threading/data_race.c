#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //POSIX standard threading library.

// thread body functions need to have this signature. 
void* thread_body_1(void* arg){
	int* shared_var_ptr = (int*)arg;
	(*shared_var_ptr)++;
	printf("%d\n", *shared_var_ptr);
	return NULL;
}

void* thread_body_2(void* arg){
	int* shared_var_ptr = (int*)arg;
	*shared_var_ptr += 2;
	printf("%d\n", *shared_var_ptr);
	return NULL;
}

int main(){
	int shared_var = 0;

	//thread handlers
	pthread_t thread1;
	pthread_t thread2;

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
	return 0;
}




	


