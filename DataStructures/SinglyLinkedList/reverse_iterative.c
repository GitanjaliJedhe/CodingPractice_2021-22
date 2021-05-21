// Iterative C program to reverse a linked list

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

void reverse(struct Node **head_ref)
{
	struct Node *prev = NULL;
	struct Node *curr = *head_ref;
	struct Node *next = NULL;

	while(curr != NULL)
	{
		next = curr -> next;
		curr -> next = prev;

		prev = curr;
		curr = next;
	}
	*head_ref = prev;
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
    
    reverse(&head);

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
