#include<stdio.h>

#include "tree.h"

int main(){

    displayNode(createNode(20));

    tree * tree1 = createtree(99);
    insert_mostRight(tree1, 89);
    insert_mostRight(tree1, 67);
    insert_mostLeft(tree1, 40);
    insert_mostLeft(tree1, 30);
    printf("\nIn order\n");
    printTreeInorder(tree1->root_node);

    printf("\nPost order\n");

    printPostOrder(tree1->root_node);

    return 0;
}