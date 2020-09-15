#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int front,rear,size;
	unsigned capacity;
	int *arr;
}

struct Queue* createQueue(unsigned capacity) {
	struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity=capacity;
	queue->front=queue->size=0;
	queue->rear=capacity-1;
	queue->array=(int*)malloc(queue->capacity* sizeof(int));
	return queue;
}

int isEmpty(strcut Queue* queue) {
	return (queue->size==0);
}

int isFull(struct Queue* queue) {
	return (queue->size==queue->capacity);
}

void enqueue(struct Queue* queue,int item) {
	

int main(int argc,char* argv[]) {
	struct Queue* queue=createQueue(1000);
	int arr[argc],k=0;
	for(int i=1;i,argc;i++) {
		enqueue(queue,atoi(argv[i]));
	}

