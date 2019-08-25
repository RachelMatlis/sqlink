#include<stdio.h>
#include<stdlib.h>

#include"BST.h"

typedef struct Node Node;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Tree {
	Node* root;
};

static int isBigger = 0;



Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (!newNode) {
		return NULL;
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Tree* createTree()
{
	Tree* t = (Tree*)malloc(sizeof(Tree));
	if (!t) {
		return NULL;
	}

	t->root = NULL;

	return t;

}

int insert(Tree** t, int data)
{
	Node *tempNode = NULL, *currNode = NULL , *newNode = NULL;

	/*Create a new Node containing the new element*/
	newNode = createNode(data);

	/*Pointer to start traversing from root and traverses downward path to search where the new Node to be inserted */
	tempNode = (*t)->root;

	while (tempNode != NULL)
	{
		currNode = tempNode;
		if (data < tempNode->data)
		{
			tempNode = tempNode->left;
		}
			
		else
		{
			tempNode = tempNode->right;
		}
	}

	/* If root is NULL the Tree is empty so The new Node is the root Node */
	if (currNode == NULL)
	{
		currNode = newNode;
		(*t)->root = currNode;
	}

	/*If the new data is less then the leaf Node data Assign the new Node to be its left child */
	else if (data < currNode->data)
	{
		currNode->left = newNode;
	}
		
	/* else assign the new Node its right child */
	else
	{
		currNode->right = newNode;
	}
		
	return 1;
}



static int searchDataByNodes(Node* node, int data)
{
	// Base Cases: root is null or data is present at root 
	if (node == NULL)
		return 0;
	if (node->data == data)
		return 1;

	// data is greater than root's data 
	if (node->data > data)
		return searchDataByNodes(node->left, data) + 0;

	// data is smaller than root's data 
	return searchDataByNodes(node->right, data) + 0;
}

int search(Tree* t, int data)
{
	return searchDataByNodes(t->root, data);
}

int delte(Tree** t, int data)
{
	return 1;
}

static void destroyByNodes(Node* node)
{
	if (!node) {
		return;
	}

	destroyByNodes(node->left);
	node->left = NULL;
	destroyByNodes(node->right);
	node->right = NULL;
	free(node);
}

int destroy(Tree** t)
{
	if (!(*t))
	{
		return  0;
	}

	destroyByNodes((*t)->root);

	return  1;
}

int walk(Tree* t, treeWalk wlakFunc, TreeWalk order)
{
	if (t)
	{
		wlakFunc(t, order);
	}	
}

//// funnction to delete a node
//struct node* delete(Node *root, int data)
//{
//	//searching for the item to be deleted
//	if (root == NULL)
//		return NULL;
//
//	if (data > root->data)
//		root->right = delete(root->right, data);
//	else if (data < root->data)
//		root->left = delete(root->left, data);
//	else
//	{
//		//No Children
//		if (root->left == NULL && root->right == NULL)
//		{
//			free(root);
//			return NULL;
//		}
//
//		//One Child
//		else if (root->left == NULL || root->right == NULL)
//		{
//			struct node *temp;
//			if (root->left == NULL)
//				temp = root->right;
//			else
//				temp = root->left;
//			free(root);
//			return temp;
//		}
//
//		//Two Children
//		else
//		{
//			Node *temp = find_minimum(root->right);
//			root->data = temp->data;
//			root->right = delete(root->right, temp->data);
//		}
//	}
//	return root;
//}

