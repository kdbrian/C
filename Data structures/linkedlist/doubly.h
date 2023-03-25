/***
 * a doubly linked list is a type of linked list where 
 * each node has a reference to the node before
 * and after it
 * 
 *      +-----------=       +-----------=       +-----------=
 *      +  Node A   =       +  Node B   =       +   Node C  =
 *      +-----------=       +-----------=       +-----------=
 *      +-  node B -=  -->  +-  node C -=  -->  +-   NULL  -=
 *      +-----------=       +-----------=       +-----------=
 *      +-  NULL   -=  <--  +-  node A -=  <--  +-  node B -=
 *      +-----------=       +-----------=       +-----------=
*/
#include<stdlib.h>

typedef struct {
    int data;
    void * next_node;
    void * prev_node;
}doubly_node;

doubly_node * create_doublyNode(int data){

    doubly_node * new_node = malloc(sizeof(doubly_node));
    new_node ->data = data;
    new_node ->next_node = NULL;
    new_node ->prev_node = NULL;

    printf("New node created at %p with %d\n", new_node, new_node->data);

    return new_node;
}


void print_node(doubly_node * node){
    printf("Node@%p\n", node);
    printf("Prev Node@%p\n", node->prev_node);
    printf("Data : %d\n", node->data);
    printf("Next Node@%p\n", node->next_node);
}

typedef struct {
    doubly_node * head;
    int size;
    doubly_node * tail;
}doubly_list;
