/***
 * 
 * 
 * circlic are type of doubly linked list but : 
 *      ? the reference of next node of the tail is the head node
 *      ? the reference of previous node of the head is the tail node
 * 
    *              +-------------------------------------------------+
    *              |                                                 |
    *      +-----------=       +-----------=       +-----------=     |
    *      +  Node A   =       +  Node B   =       +   Node C  =     |
    *      +-----------=       +-----------=       +-----------=     |
    *      +-  node B -=  -->  +-  node C -=  -->  +- Node A  -= -----
    *      +-----------=       +-----------=       +-----------=
    *  ----+-  Node C -=  <--  +-  node A -=  <--  +-  node B -=
    *  |   +-----------=       +-----------=       +-----------=
    *  |                                                |
    *  +-----------------------------------------------+    
*/
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
    int data;
    void * next_node;
    void * prev_node;

}circlic_node;

circlic_node * create_circlicNode(int data){

    circlic_node * new_node = malloc(sizeof(circlic_node));
    new_node ->data = data;
    new_node ->next_node = new_node;
    new_node ->prev_node = new_node;

    printf("New node created at %p with %d\n", new_node, new_node->data);

    return new_node;
}

void print_node(circlic_node * node){
    printf("Node@%p\n", node);
    printf("Prev Node@%p\n", node->prev_node);
    printf("Data : %d\n", node->data);
    printf("Next Node@%p\n", node->next_node);
}


typedef struct {
    circlic_node * head;
    int size;
    circlic_node * tail;
}circlic_list;

/**
 * initializes a new list by passing the element to be stored at the head as the only argument
*/
circlic_list * list_init(int head_element){

    circlic_list * new_list = malloc(sizeof(circlic_list));

    new_list->head = create_circlicNode(head_element);
    new_list->tail = new_list->head;
    new_list->size +=1;
    printf("List created @%p\n", new_list);
    return new_list;
}

/**
 * prints a given list 
*/
void print_list(circlic_list * list){
    printf("List capacity at %d\n", list->size);

    circlic_node * head = list->head;
    int counter=0;
    while (counter < list->size){
        printf("{Node:%p, next:%p, prev:%p, data:%d} \n=> ", head, head->next_node, head->prev_node, head->data);
        head=head->next_node;
        counter++;
    }
    printf("\n");
}

/**
 * inserts a node at the end of an unempty list
*/
void insert_node(circlic_list * list, int data){

    circlic_node * tail_node =list->tail;

    if(list->size <=0 || tail_node == NULL){
        printf("Error inserting node the list is blank");
        return;
    }

    circlic_node * new_node = create_circlicNode(data);

    tail_node->next_node = new_node;
    new_node->prev_node = tail_node;
    new_node->next_node=list->head;
    list->head->prev_node=new_node;

    list->tail = new_node;
    list->size ++;
}

/**
 * checks if a given list contains the given element
*/
bool contains(circlic_list * list, int data){
    
    circlic_node * head_node = list->head;
    
    if(head_node == NULL || list->size ==0){
        printf("Error : List is empty\n");
        return false;
    }

    int counter=0;
    while (counter< list->size){
        if(head_node->data == data)
            return true;
            
        head_node=head_node->next_node;
        counter++;
    }

    return false;
}

/***
 * 
 * Deletes the node with the specified data from the given list
 * on success returns the data that was contained in that node
*/
int delete_node(circlic_list * list, int data){

    circlic_node * tempnode = list->head;

    if(!contains(list,data)){
        printf("The element given %d is not in the list\n");
        return -1;
    }
    
    //?search for the element
    circlic_node * prevnode;
    while ( tempnode->data != data){
        prevnode = tempnode;//finally points to the node just before the one to delete
        tempnode = (circlic_node *) tempnode->next_node;//finally points to the node to be deleted 
    }

    int el=tempnode->data;
    // printf("Successfully retrieved %d and deleted node\n", el);

    //? change the references
    //? check if the node was at the end of the list
    if(tempnode->next_node == list->head){
        prevnode->next_node = list->head;
        list->head->prev_node=prevnode;
        list->tail = prevnode;
        
    }else{

        ((circlic_node *)(tempnode->next_node))->prev_node = prevnode;//converting pointer for referencing

        prevnode->next_node = tempnode->next_node;

        // printf("Successfully retrieved %d and deleted node", el);
    }

    //? free the memory previously occupied by it
    tempnode = NULL;
    list->size -- ;
    return el;
}

/**
 * checks if a given list is empty by counter checking the size element of the list
*/
bool isEmpty(circlic_list * list){
    return list->size == 0 ? true : false ;
}

/**
 * Inserts a node at an arbitrary position in the list
 * 
*/
void insert_at(circlic_list * list, int position, int data){

    if(position > list->size || isEmpty(list)){
        printf("cannot insert at that position");
        return;
    }else if(position == list->size){//if the position is at the end of the list
        insert_node(list, data);
        return;
    }

    int counter =1;

    circlic_node * temphead = list->head;
    circlic_node * prevnode;

    while(counter < position){
        prevnode=temphead;
        temphead = temphead->next_node;
        counter++;
    }

    circlic_node * new_node = create_circlicNode(data);

    
    new_node->next_node = temphead;
    temphead->prev_node = new_node;

    prevnode->next_node = new_node;
    new_node->prev_node = prevnode;

    list->size++;
}
