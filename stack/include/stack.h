#include <stdio.h>
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

typedef struct node
{
    void *data;
    struct node *next;
}sNode;

sNode* createNode(void*);
void push(sNode**, void*);
void* pop(sNode**);
void* peek(sNode*);

void printInt(void*);
void printFloat(void*);
#endif
