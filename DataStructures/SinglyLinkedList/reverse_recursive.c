// Recursive C program to reverse a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
  int data;
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


struct Node * reverse(struct Node *head)
{
	if((head == NULL) || (head -> next == NULL))
		return head;

	/* reverse the rest list and 
	 * put the first element at the end*/
	struct Node *rest = reverse(head -> next);
	head -> next -> next = head;

	// tricky step
	head -> next = NULL;

	// fix the head pointer
	return rest;
}


int main()
{
    struct Node *head = NULL;
    
    insert_at_first(&head, 999);
    insert_at_first(&head, 888);
    insert_at_first(&head, 777);
    insert_at_first(&head, 666);
    insert_at_first(&head, 555);
    
    printf("Given linked list\n");
    printLL(head);
    
    head = reverse(head);

    printf("Reversed linked list\n");
    printLL(head);

    return 0;
}

/* Time Complexity  : O(n)
 * Space Complexity : O(1)
 * */

/*
Output:
Given linked list
555 -> 666 -> 777 -> 888 -> 999 ->  NULL
Reversed linked list
999 -> 888 -> 777 -> 666 -> 555 ->  NULL
*/
