#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct QueueNode
{
	int item;
	struct QueueNode *next;
};

struct Queue
{
	struct QueueNode *front;
	struct QueueNode *rear;
};

struct Queue *createQueue()
{
	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));

	queue -> front = queue -> rear = NULL;

	return queue;
}

struct QueueNode *newNode(int item)
{
	struct QueueNode *qNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));

	qNode -> item = item;
	qNode -> next = NULL;

	return qNode;
}

void enqueue(struct Queue *queue, int item)
{
	struct QueueNode *qNode = newNode(item);

	if(queue -> rear == NULL)
	{
		queue -> front = queue -> rear = qNode;
		printf("%d enqueued to queue\n", item);
		return;
	}

	queue -> rear -> next = qNode;
	queue -> rear = qNode;
	printf("%d enqueued to queue\n", item);
}

int isEmpty(struct Queue *queue)
{
	return queue -> front == NULL;
}

int dequeue(struct Queue *queue)
{
	if(isEmpty(queue))
	{
		return INT_MIN;
	}

	struct QueueNode *temp = queue -> front;
	queue -> front = queue -> front -> next;
	
	// If front becomes NULL, then change rear also to NULL 
	if(queue -> front == NULL)
	{
		queue -> rear = NULL;
	}

	int item = temp -> item;

	free(temp);

	return item;
}

int front(struct Queue *queue)
{
	return queue -> front -> item;
}

int rear(struct Queue *queue)
{
	return queue -> rear -> item;
}

int main()
{

	struct Queue *queue = createQueue();

	enqueue(queue, 555);
	enqueue(queue, 666);
	enqueue(queue, 777);
	enqueue(queue, 888);
	enqueue(queue, 999);

	printf("\n%d dequeued from queue\n\n", dequeue(queue));

	printf("Queue front is %d\n", front(queue));
	printf("Queue rear is %d\n", rear(queue));

	return 0;
}

/*Time Complexity:
 * enqueue() and dequeue() is O(1)
 * 	because we change only few pointer in both operations. There is no loop in any of the operations
 * */

/*Output:
555 enqueued to queue
666 enqueued to queue
777 enqueued to queue
888 enqueued to queue
999 enqueued to queue

555 dequeued from queue

Queue front is 666
Queue rear is 999
 */
