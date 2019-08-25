#ifndef H_BINARYTree

#define H_BINARYTree


typedef enum { Preorder, Inorder, Postorder} TreeWalk;
typedef struct Tree Tree;
typedef void(*treeWalk)(Tree* t, TreeWalk treewalkOrder);

Tree* createTree();
int insert(Tree** , int );

int search(Tree* , int data);
int delte(Tree** , int data);
int destroy(Tree** );
int walk(Tree* t, treeWalk wlakFunc, TreeWalk order);

#endif