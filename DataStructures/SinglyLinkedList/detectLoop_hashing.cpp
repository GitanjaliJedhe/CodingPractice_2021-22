// Detect loop in linked list using hasing

#include <iostream>
#include <unordered_set>

using namespace std;

struct Node 
{
  int data;
  struct Node *next;
};

void insert_at_first(struct Node **head_ref, int value)
{
	struct Node *new_node = new Node;

	new_node -> data = value;
	new_node -> next = *head_ref;

	(*head_ref) = new_node;
}

bool detectLoop(struct Node *head) 
{
	unordered_set<Node*> s;
	
	while(head != NULL)
	{
		// If this node is alreay present in hashmap
		// it means there is a cycle
		if(s.find(head) != s.end())
		{
			return true;
		}

		//If we are seeing the node for the first time, insert it in hash 
		s.insert(head);
		head = head -> next;
	}
	return false;
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


    if(detectLoop(head) == true)
    {
	    cout<<"Loop found"<<endl;
    }
    else
    {
	    cout<<"No Loop"<<endl;
    }

    return 0;
}

/* Time Complexity  : O(n)
 * Space Complexity : O(n) 
 * 	n is the space required to store the value in hashmap
 * */

/*Output:
 * Loop found
 * */
