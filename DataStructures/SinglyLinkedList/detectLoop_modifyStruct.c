// Detect loop in linked list by modifying the linked list data structure

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
	while(head != NULL)
	{
		// If node is already traverse
		// it means there is cycle
		if(head -> flag == 1)
		{
			return TRUE;
		}

		// If we are seeing the node for 
		// the first time, mark its flag as 1  
		head -> flag = 1;
		head = head -> next;
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
