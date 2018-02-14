#include <stdio.h>
#include "stack.h"

int main()
{
    sNode *head=NULL;
    int arr[]={30, 20, 10};
    
    int size=sizeof(int);

    for(int i=0; i < 3; i++)
    {
        push(&head, &arr[i]);
    }

    while (head)
        printf("%d ", *(int*)pop(&head));

    return 0;
}
