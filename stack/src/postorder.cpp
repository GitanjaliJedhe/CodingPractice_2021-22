#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct tNode
{
    int data;
    tNode *left, *right;
}tNode;

tNode* newTNode(int data)
{
    tNode *newTNode = (tNode*)malloc(sizeof(tNode));
    newTNode -> data = data;
    newTNode -> left = NULL;
    newTNode -> right = NULL;
    return newTNode;
}

void* peek(sNode* top)
{
    if (top == NULL)
        return NULL;
    return top;
}

void postorder(tNode *root)
{
    if(root == NULL)
        return;

    sNode *top = NULL;

    do
    {
        while(root != NULL)
        {
            if(root -> right != NULL)
                push(&top, root -> right);

            push(&top, root);

            root = root -> left;
        }

        root = (tNode *)pop(&top);
        
        if((top) && (root -> right) && (root->right==(top->data)))
        {
            pop(&top);
            push(&top, root);
            root = root -> right;
        }
        else
        {
             printf("%d ", root -> data);
             root = NULL;
        }
    }while(top != NULL);//Stack is not empty
}

int main()
{
    tNode* root = NULL;
    root = newTNode(1);
    root->left = newTNode(2);
    root->right = newTNode(3);
    root->left->left = newTNode(4);
    root->left->right = newTNode(5);
    root->right->left = newTNode(6);
    root->right->right = newTNode(7);

    postorder(root);

    return 0;
}
