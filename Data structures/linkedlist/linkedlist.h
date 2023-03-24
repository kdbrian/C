#include "node.h"
#include<stdbool.h>
// logical view of a linked list
typedef struct {
    node* head;
    int size;
}list;


list * list_init(int root_data){

    list * new_list = malloc(sizeof(list));

    new_list->head = create_node(root_data);
    new_list->size +=1;

    return new_list;
}

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

int getsize(list * lst){
    return lst->size;
}

void print_list(list * lst){
    node * temphead = lst->head;

    while (temphead != NULL){
        printf("Node[@%p]:%d -> ", temphead, temphead->element);
        temphead=temphead->next;
    }
}

bool contains(list * lst, int el){

    if(lst == NULL)
        return false;
    node * tnode = lst->head;

    while(tnode != NULL){ 
        if(tnode->element = el)
            return true;
        tnode=tnode->next;
    }
    return false;
}

void remove_node(list * lst, int data){

        if(!contains(lst,data)){
            printf("The element %d is not available in the list\n", data);
            return;
        }

        node * temphead = lst->head;
        node * prevnode;

        while(temphead != NULL){
           
        }
}