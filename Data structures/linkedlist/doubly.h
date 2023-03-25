/***
 * a doubly linked list is a type of linked list where 
 * each node has a reference to the node before
 * and after it
 * 
 *      +-----------=       +-----------=       +-----------=
 *      +  Node A   =       +  Node B   =       +   Node C  =
 *      +-----------=       +-----------=       +-----------=
 *      +-  node B -=  -->  +-  node C -=  -->  +-   NULL  -=
 *      +-----------=       +-----------=       +-----------=
 *      +-  NULL   -=  <--  +-  node A -=  <--  +-  node B -=
 *      +-----------=       +-----------=       +-----------=
*/
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int data;
    void * next_node;
    void * prev_node;
}doubly_node;

doubly_node * create_doublyNode(int data){

    doubly_node * new_node = malloc(sizeof(doubly_node));
    new_node ->data = data;
    new_node ->next_node = NULL;
    new_node ->prev_node = NULL;

    printf("New node created at %p with %d\n", new_node, new_node->data);

    return new_node;
}


void print_node(doubly_node * node){
    printf("Node@%p\n", node);
    printf("Prev Node@%p\n", node->prev_node);
    printf("Data : %d\n", node->data);
    printf("Next Node@%p\n", node->next_node);
}

typedef struct {
    doubly_node * head;
    int size;
    doubly_node * tail;
}doubly_list;

/**
 * initializes a new list by passing the element to be stored at the head as the only argument
*/
doubly_list * list_init(int head_element){

    doubly_list * new_list = malloc(sizeof(doubly_list));

    new_list->head = create_doublyNode(head_element);
    new_list->tail = new_list->head;
    new_list->size +=1;
    printf("List created @%p\n", new_list);
    return new_list;
}

/**
 * prints a given list 
*/
void print_list(doubly_list * list){
    printf("List capacity at %d\n", list->size);

    doubly_node * head = list->head;
    while (head != NULL){
        printf("{Node:%p, next:%p, prev:%p, data:%d} => ", head, head->next_node, head->prev_node, head->data);
        head=head->next_node;
    }
    printf("\n");
}

/**
 * inserts a node at the end of an unempty list
*/
void insert_node(doubly_list * list, int data){

    doubly_node * tail_node =list->tail;

    if(list->size <=0 || tail_node == NULL){
        printf("Error inserting node the list is blank");
        return;
    }

    doubly_node * new_node = create_doublyNode(data);

    tail_node->next_node = new_node;
    new_node->prev_node = tail_node;

    list->tail = new_node;
    list->size ++;
}

/**
 * checks if a given list contains the given element
*/
bool contains(doubly_list * list, int data){
    
    doubly_node * head_node = list->head;
    
    if(head_node == NULL || list->size ==0){
        printf("Error : List is empty\n");
        return false;
    }

    doubly_node * prev;
    while (head_node != NULL){
        if(head_node->data == data)
            return true;
            
        head_node=head_node->next_node;
    }

    return false;
}

/***
 * 
 * Deletes the node with the specified data from the given list
 * on success returns the data that was contained in that node
*/
int delete_node(doubly_list * list, int data){

    doubly_node * head_node = list->head;

    if(!contains(list,data)){
        printf("The element given %d is not in the list\n");
        return -1;
    }
    
    //?search for the element
    doubly_node * prevnode;
    while ( head_node->data != data){
        prevnode = head_node;//finally points to the node just before the one to delete
        head_node = (doubly_node *) head_node->next_node;//finally points to the node to be deleted 
    }

    int el=head_node->data;
    // printf("Successfully retrieved %d and deleted node\n", el);

    //? change the references
    //? check if the node was at the end of the list
    
    if(head_node->next_node == NULL){
        prevnode->next_node = NULL;
        list->tail = prevnode;
        
    }else{

        ((doubly_node *)(head_node->next_node))->prev_node = prevnode;//converting pointer for referencing

        prevnode->next_node = head_node->next_node;

        // printf("Successfully retrieved %d and deleted node", el);
    }

    //? free the memory previously occupied by it
    head_node = NULL;
    list->size -- ;
    return el;
}

/**
 * checks if a given list is empty by counter checking the size element of the list
*/
bool isEmpty(doubly_list * list){
    return list->size == 0 ? true : false ;
}

/**
 * Inserts a node at an arbitrary position in the list
 * 
*/
void insert_at(doubly_list * list, int position, int data){

    if(position > list->size || isEmpty(list)){
        printf("cannot insert at that position");
        return;
    }else if(position == list->size){//if the position is at the end of the list
        insert_node(list, data);
        return;
    }

    int counter =1;

    doubly_node * temphead = list->head;
    // doubly_node * prevnode;

    while(counter < position){
        // prevnode=temphead;
        temphead = temphead->next_node;
        counter++;
    }

    doubly_node * new_node = create_doublyNode(data);

    new_node->next_node = temphead->next_node;
    ((doubly_node *)temphead->next_node)->prev_node = new_node;

    temphead->next_node = new_node;
    new_node->prev_node = temphead;
    list->size++;
}

