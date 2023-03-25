/*

    representation of linked list
    nodes linked through pointers
    a node contains an element and a link to the next node in the list

                *===========*
                *  element  + 
                *===========*
                * link_next +
                *===========*

        [head]                                                              [tail]
        0xe21j                0xcw45                  0xo2k3                0xklmd
    +------------+        +------------+          +------------+         +------------+                       
    +---  10  ---+  +====>+---  20  ---+   +=====>+---  30  ---+  +=====>+---  40  ---+                       
    +------------+  |     +------------+   |      +------------+  |      +------------+                       
    +---0xcw45---+  |     +---0xo2k3---+   |      +---0xklmd---+  |      +----NULL----+                       
    +------------+  |     +------------+   |      +------------+  |      +------------+                       
          |         |            |         |            |         |            |
          +---------+            +---------+            +---------+            +=>+-----+
                                                                                  |#####|
                                                                                  +-----+
    size = 4
*/
#include<stdio.h>
#include "linkedlist.h"

int main(){

    list * list1 = list_init(0);
    //node * hd = create_node(10);
    insert(list1, 10);
    insert(list1, 20);
    insert(list1, 40);
    printf("Size of list is %d\n", getsize(list1));
    print_list(list1);

    //printf("\nNode 0 at position %d\n", search_node(list1,0));

    remove_node(list1, 20);

    print_list(list1);

    remove_front(list1);

    print_list(list1);

    remove_front(list1);

    print_list(list1);

    remove_node(list1,40);

    print_list(list1);

    printf("List capacity at %d\n", getsize(list1));

    list * list2 = list_init(0);
    insert(list2,10);
    insert(list2,20);
    insert(list2,30);
    printf("List capacity at %d\n", getsize(list2));
    print_list(list2);

    insert_at(list2, 99, 3);
    print_list(list2);
   
    return 0;
}
