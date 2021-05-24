// C program to implement Stack using Array

/*Pros: Easy to implement. Memory is saved as pointer is not involved
 *Cons: It is not dynamic. It doesn't grow and shrink depending on needs at runtime 
 * */

#include <stdio.h>
#include <stdlib.h> // malloc
#include <limits.h> // INT_MIN

struct Stack
{
	unsigned capacity;
	int top;
	int *array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array = (int *)malloc(stack -> capacity * sizeof(int));

	return stack;
}

int isFull(struct Stack *stack)
{
	return (stack -> top == stack -> capacity - 1);
}

int isEmpty(struct Stack *stack)
{
	return (stack -> top == -1);
}

void push(struct Stack *stack, int item) 
{
	if(isFull(stack))
	{
		return;
	}

	stack -> array [++stack -> top] = item;

	printf("%d is pushed to stack\n", item);
}

int pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		return INT_MIN;
	}

	return stack -> array[stack -> top--];
}

int peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		return INT_MIN;
	}

	return stack -> array[stack -> top];
}

int main()
{
	struct Stack *stack = createStack(100);

	push(stack, 555);
	push(stack, 666);
	push(stack, 777);
	push(stack, 888);
	push(stack, 999);

	printf("\n%d popped from stack\n", pop(stack));

	printf("\nTop element is %d\n", peek(stack));

	return 0;
}

/* Time Complexity
 * push(), pop(), isEmpty(), and peek() : O(1) 
 * 	We do not run any loop in any of these operation 
 * */

/* Output:
   555 is pushed to stack
   666 is pushed to stack
   777 is pushed to stack
   888 is pushed to stack
   999 is pushed to stack

   999 popped from stack

   Top element is 888

*/

