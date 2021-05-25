#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Pros:
 * 1. Easy to implement
 *
 * Cons:
 * 1. Static Data Structure, fixed size
 * 2. If the queue has a large number of enqueue and dequeue opeartion, at same
 * point we may not able to insert element in the queue even if the queue is empty
 * (Solution circular queue)
 * */

struct Queue
{
	int front, rear, size;
	unsigned capacity;
	int *array;
};

struct Queue *createQueue(int capacity)
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	
	queue -> capacity = capacity;

	queue -> front = queue -> size = 0;

	// This is important, see the enqueue
	queue -> rear = capacity - 1;

	queue -> array = (int *)malloc(queue -> capacity * sizeof(int));

	return queue;
}

int isFull(struct Queue *queue)
{
	return (queue -> size == queue -> capacity);
}

void enqueue(struct Queue *queue, int item)
{
	if(isFull(queue))
	{
		return;

	}
	
	queue -> rear = (queue -> rear + 1) % queue -> capacity; // queue -> rear value 0..9

	queue -> array[queue -> rear] = item;
	queue -> size = queue -> size + 1;
	printf("%d enqueued to queue\n", item);
}

int isEmpty(struct Queue *queue)
{
	return (queue -> size == 0);
}

int dequeue(struct Queue *queue)
{
	if(isEmpty(queue))
	{
		return INT_MIN;
	}

	int item = queue -> array[queue -> front];
	queue -> front = (queue -> front + 1) % queue -> capacity;
	queue ->size = queue -> size - 1;
	return item;
}


int front(struct Queue *queue)
{
	if(isEmpty(queue))
	{
		return INT_MIN;
	}
	return queue -> array[queue -> front];
}


int rear(struct Queue *queue)
{
	if(isEmpty(queue))
	{
		return INT_MIN;
	}
	return queue -> array[queue -> rear];
}

int main()
{
	struct Queue *queue = createQueue(10);

	enqueue(queue, 555);
	enqueue(queue, 666);
	enqueue(queue, 777);
	enqueue(queue, 888);
	enqueue(queue, 999);

	
	printf("\n%d dequeued from queue\n\n", dequeue(queue));
	
	printf("front item is %d\n", front(queue));
	printf("rear item is %d\n", rear(queue));

	return 0;
}

/*Time Complexity:
 * Enque O(1)
 * Deque O(1)
 * Front O(1)
 * Rear  O(1)
 *
 *Space Complexity: O(N)
 * N is the size of array for storing elements	
 * */

/*Output:
555 enqueued to queue
666 enqueued to queue
777 enqueued to queue
888 enqueued to queue
999 enqueued to queue

555 dequeued from queue

front item is 666
rear item is 999
**/
