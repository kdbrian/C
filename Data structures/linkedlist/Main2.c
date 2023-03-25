/**
 * 
 *  This file contains the code related to doubly.h which represents a doubly linked list
 * 
*/
#include<stdio.h>
#include "doubly.h"

int main(){
    
    doubly_node * node1 = create_doublyNode(10);
    print_node(node1);

    doubly_list * list1 = list_init(20);
    insert_node(list1,30);
    insert_node(list1,40);
    insert_node(list1,50);
    insert_node(list1,60);

    print_list(list1);

    printf("\n");
    delete_node(list1,50);
    print_list(list1);
    printf("\n");
    insert_at(list1,3,99);
    printf("\n");
    print_list(list1);

    printf("\n");
    insert_at(list1,5,909);
    printf("\n");
    print_list(list1);


    return 0;
}
