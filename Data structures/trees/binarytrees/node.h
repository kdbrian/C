/**
 * 
 * the logical view of a node of a binary tree
 * 
 * a binary tree is a tree whose children can only have two or less sibblings
 * 
 *                            +---------+
 *                            +--- R ---+
 *                            +---------+
 *             +--------------+--A - B--+--------------+
 *             \              +---------+              \      
 *             \                                       \
 *        +---------+                               +---------+                              
 *        +--- A ---+                               +--- B ---+
 *        +---------+                               +---------+
 *        +---------+                               +---------+
 *        +---------+                               +---------+
 * 
*/
#include<stdlib.h>

typedef struct{
    int data;
    void * left_child;
    void * right_child;
} node;


node * createNode(int data){

    node * new_node = malloc(sizeof(node));

    new_node->data = data;
    new_node->left_child  = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void displayNode(node * _node){
    printf("Node [%d] @%p\n", _node->data , _node);
    printf("Left child @%p\n", _node->left_child);
    printf("Right child @%p\n", _node->right_child);
    printf("\n");
}