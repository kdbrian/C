/**
 * 
 * the representation of a binary tree
*/
#include "node.h"
typedef struct {

    int size;
    node * root_node;
    
}tree;


tree * createtree(int root_data){

    tree * new_tree = malloc(sizeof(tree));

    
    node * root = createNode(root_data);
    
    new_tree ->root_node = root;

    new_tree->size ++;

    return new_tree;
}

void insert_mostLeft(tree * tr, int data){
    if (tr == NULL)
        return;
    else{
        node * prev;
        node * temp = tr->root_node;

        while(temp != NULL){
            prev = temp;
            temp = temp->left_child;
        }

        node * new_node = createNode(data);

        prev->left_child = new_node;
        tr->size ++;
    }
    
}

void insert_mostRight(tree * tr, int data){
    if (tr == NULL)
        return;
    else{
        node * prev;
        node * temp = tr->root_node;

        while(temp != NULL){
            prev = temp;
            temp = temp->right_child;
        }

        node * new_node = createNode(data);

        prev->right_child = new_node;
        tr->size ++;
    }
    
}

void printTreeInorder(node * root){
    if(root == NULL)
        return;
    else
        printTreeInorder(root->left_child);
        printf("Node[%d]\n", root->data);
        printTreeInorder(root->right_child);
}

void printPostOrder(node * root){

    if(root == NULL)
        return;
    else{
        printPostOrder(root->left_child);
        printPostOrder(root->right_child);
        printf("Node[%d]\n", root->data);
    }
}

void printPreOrder(node * root){

    if(root == NULL)
        return;
    else{
        printf("Node[%d]\n", root->data);
        printPreOrder(root->left_child);
        printPreOrder(root->right_child);
    }
}

