#include <stdio.h>
#include "stack.h"

struct tNode
{
    int data;
    struct tNode *left, *right;
};

void inOrder(struct tNode *root)
{
    struct tNode *current = root;
    sNode *top = NULL;
    bool flag = 0;

    while(!flag)
    {
        if(current != NULL)
        {
            push(&top, current);
            current = current -> left;
        }
        else
        {
            if(top != NULL)//Stack is not empty
            {
                current = (struct tNode*)pop(&top);
                printf("%d ", current->data);
                current = current -> right;
            }
            else
            {
                flag = 1;
            }
        }
    }
}

struct tNode* newTNode(int data)
{
    struct tNode *tNode = (struct tNode*)malloc(sizeof(struct tNode));

    tNode -> data = data;
    tNode -> left = NULL;
    tNode -> right = NULL;

    return tNode;
}

int main()
{
    struct tNode *root;

    //tree construction
    root = newTNode(10);
    root -> left = newTNode(20);
    root -> right = newTNode(30);
    root -> left -> left  = newTNode(40);
    root -> left -> right = newTNode(50);

    inOrder(root);

    return 0;
}
