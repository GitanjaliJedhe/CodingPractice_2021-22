// Detect and remove loop (Check one by one)
 
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
	struct Node *ptr1, *ptr2;

	ptr1 = head;
	while(TRUE)
	{
		/* Start a pointer from loop_node and check if 
		 * it reaches ptr2 
		 * */
		ptr2 = loop_node;
		while(ptr2 -> next != loop_node && ptr2 -> next != ptr1)
		{
			ptr2 = ptr2 -> next;
		}

		/*If ptr2 reached ptr1 then there is a loop. So break the loop*/
		if(ptr2 -> next == ptr1)
		{
			break;
		}
	
		ptr1 = ptr1 -> next;
	}

	/* After the end of loop ptr2 is the last node of loop.
	 * So make next of ptr2 as NULL*/
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
