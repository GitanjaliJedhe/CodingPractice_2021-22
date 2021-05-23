// Detect and Remove loop in linked list using hasing

#include <iostream>
#include <unordered_set>

using namespace std;

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
	struct Node *new_node = new Node;

	new_node -> data = value;
	new_node -> next = *head_ref;

	(*head_ref) = new_node;
}

bool detectAndRemoveLoop(struct Node *head) 
{
	unordered_set<Node*> s;
	
	// Pointer to last node
	Node *last = NULL;
	while(head != NULL)
	{
		// If node is not present in the set, insert it in set
		if(s.find(head) == s.end())
		{
			s.insert(head);
			last = head;
			head = head -> next;
		}
		// If present, it is cycle, make the last node's next pointer NULL
		else
		{
			last -> next = NULL;
			break;
		}
	}
}

int main()
{
    struct Node *head = NULL;
    
    insert_at_first(&head, 999);
    insert_at_first(&head, 888);
    insert_at_first(&head, 777);
    insert_at_first(&head, 666);
    insert_at_first(&head, 555);

    head -> next -> next -> next -> next -> next = head;

    detectAndRemoveLoop(head);

    cout<<"Linked list after removing loop"<<endl;
    printLL(head);

    return 0;
}

/*Output:
 *Linked list after removing loop
 *555 -> 666 -> 777 -> 888 -> 999 ->  NULL
 * */
