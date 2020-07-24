/*
 * This shows how c can be programmed in an object-oriented way
 * How objects have initializers that are run after their memory
 * is allocated. Objects can also own their own memory and are
 * responsible for freeing it when they are deleted.
 */

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE 100

typedef struct {
	int front;
	int rear;
	double* arr; // init has to allocate this array
} queue_t;

// just like self-methods in python, but these have to 
// explicitly pass in the "self" as a pointer. no problem!
// these are only implicitly related to the object type that
// they are managing. 

void init(queue_t* q){
	q->front = q->rear = 0;
	// this heap memory is owned by
	// the queue object.
	q->arr = (double*)malloc(QUEUE_MAX_SIZE * sizeof(double));
}

void destroy(queue_t* q){
	free(q->arr);
}

int size(queue_t* q){
	return q->rear - q->front;
}

void enqueue(queue_t* q, double item){
	q->arr[q->rear] = item;
	q->rear++;
}

double dequeue(queue_t* q){
	double item = q->arr[q->front];
	q->front++;
	return item;
}

int main(){
	//heap memory here is owned by the
	//main function
	queue_t* q = (queue_t*)malloc(sizeof(queue_t));

	// allocate needed memory for queue object
	init(q);

	enqueue(q, 6.5);
	enqueue(q, 3);
	enqueue(q, 9.9);

	printf("%f\n", dequeue(q));
	printf("%f\n", dequeue(q));
	printf("%f\n", dequeue(q));

	// free memory allocated -BY-  queue object
	destroy(q);

	// free memory allocated -FOR- queue object
	free(q);

	return 0;
}


