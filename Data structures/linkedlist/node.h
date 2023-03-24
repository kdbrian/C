#include<stdlib.h>
// logical view of a node
typedef struct {
    int element;
    void * next;
}node;


node * create_node(int data){

    node * new_node = malloc(sizeof(node));

    new_node-> element = data;
    new_node->next = NULL;

    printf("Node created @_%p\t with %d\n", new_node, data);

    return new_node;
}
void print_node(node n);
