// Search in BST

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

struct node *search(struct node *root, int key)
{
	// Base case: root is null or key is present at root
	if(root == NULL || root -> key == key)
	{
		return root;
	}

	// Key is smaller than root's key
	if(key < root -> key)
	{
		return search(root -> left, key);
	}

	// Key is greater than root's key
	return search(root -> right, key);
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

	inorder(root);

	return 0;
}

/*Time Complexity
 * O(h) :  h is hight of the Binary Search Tree
 * */

/*Output:
20
30
40
50
60
70
80
*/
