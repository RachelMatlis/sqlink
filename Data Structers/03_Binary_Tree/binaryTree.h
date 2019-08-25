#ifndef H_BINARYTREE

#define H_BINARYTREE



typedef struct tree tree;


tree* createTree();
tree* insert(tree* root ,int data);

tree* search(tree* root ,int data);
tree* delte(tree* root ,int data);

#endif