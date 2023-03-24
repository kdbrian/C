/*

    representation of linked list
    nodes linked through pointers
    a node contains an element and a link to the next node in the list

                *===========*
                +  element  + 
                *===========*
                + link_next +
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
    printf("Size of list is %d\n", getsize(list1));
    print_list(list1);

    remove_node(list1, 20);
   
    return 0;
}
