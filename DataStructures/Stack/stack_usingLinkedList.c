// C program to implement stack using linked list

/* Pros: The linked list implementation of stack can grow and shrink according to the need at runtime
 * Cons: Requires extra memory due to involment of pointers
 * */

#include <stdio.h>
#include <stdlib.h> // malloc and free
#include <limits.h>

struct StackNode
{
	int data;
	struct StackNode *next;
};

struct StackNode *newNode(int item)
{
	struct StackNode *stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

	stackNode -> data = item;
	stackNode -> next = NULL;

	return stackNode;
}

void push(struct StackNode **root, int item) 
{
	struct StackNode *stackNode = newNode(item);

	stackNode -> next = *root;

	*root = stackNode;

	printf("%d pushed to stack\n", item);
}

int isEmpty(struct StackNode *root)
{
	return !root;
}

int pop(struct StackNode **root)
{
	if(isEmpty(*root))
	{
		return INT_MIN;
	}

	struct StackNode *temp = *root;
	int popped = temp -> data;
	*root = (*root) -> next;
	free(temp);

	return popped;
}

int peek(struct StackNode *root)
{
	if(isEmpty(root))
	{
		return INT_MIN;
	}

	return root -> data;
}

int main()
{

	struct StackNode *root = NULL;

	push(&root, 555);
	push(&root, 666);
	push(&root, 777);
	push(&root, 888);
	push(&root, 999);

	printf("\n%d popped from stack\n", pop(&root));

	printf("\nTop element is %d\n", peek(root));

	return 0;
}

/* Time Complexity
 * push(), pop(), isEmpty(), and peek() : O(1) 
 * 	We do not run any loop in any of these operation 
 **/


/*Output:
555 pushed to stack
666 pushed to stack
777 pushed to stack
888 pushed to stack
999 pushed to stack

999 popped from stack

Top element is 888

 */
