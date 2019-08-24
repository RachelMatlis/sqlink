#ifndef H_LINKEDLIST

#define H_LINKEDLIST

typedef struct node {
	int val;
	struct node* next;
} node_t;


node_t* pushToLinkedList(node_t*, int);
node_t* flipLinkedList(node_t*);
node_t* findMiddleOfLinkedList(node_t*);
int isALoopInALinkedList(node_t*);
node_t* FindComminNode(node_t*, node_t*);

#endif