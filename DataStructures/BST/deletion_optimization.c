// Deletion(Optimization) in BST

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *left, *right;
};

struct node* newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp-> key = item;
	temp -> left = temp -> right = NULL;

	return temp;
}

struct node* insert(struct node *root, int key)
{
	// If the tree is empty, return a new node
	if(root == NULL)
	{
		return newNode(key);
	}

	// Otherwise, recur down the tree
	if(key < root -> key)
	{
		root -> left = insert(root -> left, key);
	} else if(key > root -> key)
	{
		root -> right = insert(root -> right, key);
	}

	return root;
}

struct node *deleteNode(struct node *root, int key)
{
	// base case
	if(root == NULL)
	{
		return root;
	}

	if(key < root -> key) // key is smaller than the root's key
	{
		root -> left = deleteNode(root -> left, key);
	} else if(key > root -> key) // key is greater than the root's key
	{
		root -> right = deleteNode(root -> right, key);
	} else // if key is same as root's key 
	{
		// node with only one child or no child
		if(root -> left == NULL) 
		{
			struct node *temp = root -> right;
			free(root);
			return temp;
		}
		else if(root -> right == NULL)
		{
			struct node *temp = root -> left;
			free(root);
			return temp;
		}
		else // node with two children
		{
			struct node *succParent = root;

			// Find successor
			struct node *succ = root -> right;
			while(succ -> left != NULL)
			{
				succParent = succ;
				succ = succ -> left;
			}

			// Delete successor. 
			/* Since successor is always left child of its parent
			 * we can safely make successor's right child as left of its parent.
			 * If there is no succ, then  assign succ -> right to succParent -> right
			 * */

			if(succParent != root)
			{
				succParent -> left = succ -> right;
			} 
			else
			{
				succParent -> right = succ -> right;
			}

			// Copy successor data to root
			root -> key = succ -> key;

			free(succ);
		}

	}
	return root;
}

void inorder(struct node *root)
{
	if(root != NULL) 
	{
		inorder(root -> left);
		printf("%d\n", root -> key);
		inorder(root -> right);
	}
}

int main()
{
	/*
	 *        50
	 *      /    \
	 *    30     70
	 *   / \    /  \
	 * 20   40 60   80
	 * */
	struct node *root = NULL;
	root = insert(root, 50);

	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	printf("Inorder traversal of the given tree\n");
	inorder(root);

	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree\n");
	inorder(root);

	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree\n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree\n");
	inorder(root);

	return 0;
}

/*Time Complexity
 * O(h) :  h is hight of the Binary Search Tree
 * */

/*Output:
Inorder traversal of the given tree
20
30
40
50
60
70
80

Delete 20
Inorder traversal of the modified tree
30
40
50
60
70
80

Delete 30
Inorder traversal of the modified tree
40
50
60
70
80

Delete 50
Inorder traversal of the modified tree
40
60
70
80
*/
