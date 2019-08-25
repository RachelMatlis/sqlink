 #include<stdio.h>
#include<stdlib.h>

#include"binaryTree.h"

typedef struct node node;

struct node  
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

struct tree{
	node* root;
};

static int isBigger=0;

static node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if(!newNode){
    	return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

tree* createTree() 
{ 
  tree* t = (tree*)malloc(sizeof(tree);
  if(!t){
  	return NULL;
  }

  t->root = NULL;

  return root;

} 

tree* insert(tree* t ,int data)
{
	tree *node, *newNode;
	


	node* newNode=NULL;
	node* temp = NULL;

    newNode = createNode(data);/*if the root is null create new node and return it*/

	if(t->root == NULL)
	{
		t->root = newNode;
		return t;
	}

	if(data < t->root->data)
	{

	}
  
    
} 
  

tree* search(tree* root ,int data)
{

}

