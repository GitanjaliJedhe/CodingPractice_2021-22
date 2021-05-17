// Singly Linked List in C

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

int main()
{
    struct Node *head, *second, *third;
    
    head = second = third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    head -> data = 100;
    head -> next = second;
    
    second -> data = 200;
    second -> next = third;
    
    third -> data = 300;
    third -> next = NULL;
    
    printLL(head);
    
    return 0;
}


/*
Output:
100 -> 200 -> 300 ->  NULL
*/
