/**
 * this file relates to the code on circlic linked list as in circlic.h
*/
#include<stdio.h>
#include "circlic.h"

int main(){
    
    circlic_node * node1 = create_circlicNode(90);
    //print_node(node1);

    circlic_list * list1 = list_init(0);
    print_list(list1);

    insert_node(list1,20);
    insert_node(list1,30);
    insert_node(list1,40);
    insert_node(list1,50);
    print_list(list1);
    
    delete_node(list1, 40);
    print_list(list1);

    delete_node(list1, 50);
    print_list(list1);

    insert_at(list1,3, 50);
    print_list(list1);

    insert_at(list1,3, 99);
    print_list(list1);

    return 0;
}
