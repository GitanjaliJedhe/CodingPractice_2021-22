// Detect and remove loop by count the number of nodes in loop 
 
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


/* Function to remove loop
 * loop_node : Pointer to one of the loop node
 * head : Pointer to the start node of the linked list
 * */
void removeLoop(struct Node *loop_node, struct Node *head)
{
	struct Node *ptr1 = loop_node;
	struct Node *ptr2 = loop_node;

	// Count the number of nodes in loop
	unsigned int noOfNodes = 1;
	while(ptr1 -> next != ptr2)
	{
		noOfNodes++;
		ptr1 = ptr1 -> next;
	}

	// Fix one pointer to head
	ptr1 = head;

	// And the other pointer to noOfNodes nodes after head
	ptr2 = head;
	for(int i = 0; i < noOfNodes; i++)
	{
		ptr2 = ptr2 -> next;
	}

	/* Move both pointer at same pace,
	 * they meet at loop starting node*/
	while(ptr1 != ptr2)
	{
		ptr1 = ptr1 -> next;
		ptr2 = ptr2 -> next;
	}

	// Get pointer to the last node
	while(ptr2 -> next != ptr1)
	{
		ptr2 = ptr2 -> next;
	}

	/* Set the next pointer of loop ending node to NULL
	 * to fix the loop */
	ptr2 -> next = NULL;
}

int detectAndRemoveLoop(struct Node *head)
{
	struct Node *slow_ptr, *fast_ptr;

	slow_ptr = fast_ptr = head;

	while(slow_ptr != NULL && fast_ptr != NULL && fast_ptr -> next != NULL)
	{
		if(slow_ptr == fast_ptr)
		{
			removeLoop(slow_ptr, head);
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
 
    detectAndRemoveLoop(head);
    
    printf("Linked List after removing loop\n");
    printLL(head);

    return 0;
}

/*
Output:
Linked List after removing loop
555 -> 666 -> 777 -> 888 -> 999 ->  NULL
*/
