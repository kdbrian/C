/**
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

#include "node.h"
#include<stdbool.h>
// logical view of a linked list
typedef struct {
    node* head;
    int size;
}list;

int static_node_position=0;

list * list_init(int root_data){

    list * new_list = malloc(sizeof(list));

    new_list->head = create_node(root_data);
    new_list->size +=1;

    return new_list;
}

/**
    inserts a node at the end of the list
*/
void insert(list * lst, int data){

    node * temp = lst->head;
    node * prev ;
    
    while(temp != NULL){
        prev=temp;
        temp= temp->next;
    }

    prev->next = create_node(data);
    lst->size ++;
}

/**
    returns the number of nodes in the list
*/
int getsize(list * lst){
    return lst->size;
}

/**
    prints the entire list
*/
void print_list(list * lst){

    if(lst == NULL || lst -> head == NULL){
        printf("\nList is empty\n");
        return;
    }
    node * temphead = lst->head;
    printf("List @%p{ ", lst);
    while (temphead != NULL){
        printf("Node[@%p]:%d -> ", temphead, temphead->element);
        temphead=temphead->next;
    }

    printf(" }\n");
}

/**
    check if a list contains an element
*/
bool contains(list * lst, int el){

    if(lst == NULL)
        return false;
    node * tnode = lst->head;
    int i=1;
    while(tnode != NULL){ 
        if(tnode->element == el){
            static_node_position=i;
            return true;
        }

        tnode=tnode->next;
        i++;
    }
    return false;
}

/**
    uses the contains method internally to retrieve the position of a node in a list
    makes operations such as deletion very easy
*/
int search_node(list * lst, int data){
    if(contains(lst,data))
        return static_node_position;
    return -1;
}

/**
    to remove the element at the front of the list
*/
void remove_front(list * lst){
    //printf("\nList size is %d\t", getsize(lst));
    if(lst == NULL)
        return;
    else if(lst-> size ==1){
        lst->head =NULL;
        lst->size --;
    }
    else{
        //printf("In here\n");
        node * tnode = lst->head;
        node * new_head = tnode->next;
        tnode == NULL;
        lst->head = new_head;
        lst->size --;
    }
}


void remove_node(list * lst, int data){

        if(!contains(lst,data)){
            printf("\nThe element %d is not available in the list\n", data);
            return;
        }

        if(lst ->head -> element == data){//if we 
            remove_front(lst);
            return;
        }
        node * temphead = lst->head;
        node * prevnode=temphead;

        int counter=1;

        while(counter < search_node(lst,data)){
            prevnode=temphead;//finally points to the node before the one to be deleted
            temphead=temphead->next;//finally points to the node to be deleted
            counter++;
        }

        prevnode->next = temphead->next;
        lst->size --;
        temphead = NULL;
}

/**
 * a method to insert a node at an arbitrary position in a linked list
*/
void insert_at(list * lst, int data, int position){

    if(position > getsize(lst)){
        printf("The position is greater than the current size.");
        printf("Inserting at the end");
        insert(lst, data);
        return;
    }

    int counter =1;
    node * temphead=lst->head;
    node * prev;

    while(counter < getsize(lst) && counter < position){
        prev=temphead;
        //printf("Counter at %d on node %p\n",counter, temphead);
        temphead = temphead->next;
        counter ++;
    }
    //printf("Value of temphead is %p\n", temphead);
    node * new_node = create_node(data);

    prev->next = new_node;
    new_node->next = temphead;
    lst->size ++;
}