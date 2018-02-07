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

void preorder(tNode *root)
{
    if (root == NULL)
        return;

    sNode *top = NULL;
   
    push(&top, root);

    while(top != NULL)//Stack is not empty
    {
       tNode *node = (tNode *)pop(&top);
       printf("%d ", node->data);
       if(node -> right != NULL)
           push(&top, node -> right);
       if(node -> left != NULL)
           push(&top, node -> left);
    }
}

int main()
{
    tNode *root = NULL;

    // tree construction
    root = newTNode(1); 
    root -> left = newTNode(2);
    root -> right = newTNode(3);
    root -> left -> left = newTNode(4); 
    root -> left -> right = newTNode(5); 
    root -> right -> left = newTNode(6); 
    root -> right -> right = newTNode(7); 

    preorder(root);

    return 0;
}
