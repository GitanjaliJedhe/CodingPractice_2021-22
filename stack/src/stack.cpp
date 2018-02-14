#include "stack.h"
//#include "../include/stack.h"

sNode* createNode(void *val)
{
    if(!val)
         return NULL;

    sNode *newSNode=(sNode*)malloc(sizeof(sNode));
    newSNode->data=val;
    newSNode->next=NULL;

    return newSNode;
}

void push(sNode **head_ref, void *val)
{
    sNode *newSNode=createNode(val);
    
    if(*head_ref==NULL)
    {
        *head_ref=newSNode;
    }else
    {
        newSNode->next=*head_ref;  
        *head_ref=newSNode;
    }
}

void* pop(sNode **head_ref)
{
    if(*head_ref==NULL)
    {
        return NULL;
    }
    else
    {
        sNode *temp=NULL;
        temp=*head_ref;
        void *data=temp->data;
        *head_ref=temp->next;
        temp->data=NULL;
        temp->next=NULL;
        free(temp);
        return data;
    }
}
