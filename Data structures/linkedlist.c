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
#include<stdlib.h>
// logical view of a node
typedef struct {
    int element;
    void * next;
}node;

// logical view of a linked list
typedef struct {
    node head;
    int size;
}list;

void print_list(list lst);
void print_node(node n);

int main(){

    list list1;
    node hd , nd1;

    hd.element=10;
    hd.next=(void *)&nd1;

    list1.head=hd;
    list1.size++;

   //print_list(list1);
    //assigning this way can be very tideous

    return 0;
}
