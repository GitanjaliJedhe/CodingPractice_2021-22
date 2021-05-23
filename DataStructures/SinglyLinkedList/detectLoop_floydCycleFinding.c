// Detect loop in linked list using Floyd's Cycle-Finding Algorithm

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

struct Node 
{
  int data;
  int flag;
  struct Node *next;
};

void printLL(struct Node *pNode)
{
    while(pNode != NULL)
    {
        printf("%d -> ", pNode -> data);
        pNode = pNode -> next;
    }
    printf(" NULL\n");
}

void insert_at_first(struct Node **head_ref, int value)
{
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

	new_node -> data = value;
	new_node -> next = *head_ref;

	(*head_ref) = new_node;
}

int detectLoop(struct Node *head)
{
	struct Node *slow_ptr, *fast_ptr;

	slow_ptr = fast_ptr = head;

	while(slow_ptr != NULL && fast_ptr != NULL && fast_ptr -> next != NULL)
	{
		if(slow_ptr == fast_ptr)
		{
			return TRUE;
		}

		slow_ptr = slow_ptr -> next;
		fast_ptr = fast_ptr -> next -> next;
	}

	return FALSE;
}

int main()
{
    struct Node *head = NULL;
    
    insert_at_first(&head, 999);
    insert_at_first(&head, 888);
    insert_at_first(&head, 777);
    insert_at_first(&head, 666);
    insert_at_first(&head, 555);
    
  
    head -> next -> next -> next -> next -> next = head; 
 

    if(detectLoop(head) == TRUE) 
    {
	    printf("Loop found");
    }
    else
    {
	    printf("No Loop");
    }

    return 0;
}

/* Time Complexity  : O(n)
 * Space Complexity : O(1) 
 * 	No extra space is needed
 * */

/*
Output:
Loop found
*/
