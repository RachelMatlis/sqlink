#ifndef H_LINKEDLIST

#define H_LINKEDLIST

typedef struct node {
    int val;
    struct node* next;
} node_t;


node_t*  createList();
node_t* push(node_t* head, int val);



#endif