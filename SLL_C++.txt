// Singly Linked List in C++

#include <iostream>

using namespace std;

class Node 
{
public:
  int data;
  Node *next;
};

void printLL(Node *pNode)
{
    while(pNode != NULL)
    {
        cout << pNode -> data<<" -> " ;
        pNode = pNode -> next;
    }
    cout<<" NULL\n";
}

int main()
{
    Node *head, *second, *third;
    
    head = second = third = NULL;
    
    head = new Node();
    second = new Node();
    third = new Node();
    
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