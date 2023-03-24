#include<stdio.h>
#include<stdlib.h>
/**
    variables that point to the memory adress of other variables

                           +------------------------
                           |                        +       
                        ****************            +==> adress
        original =====> ** A **+** 10 **--- element          ^
         element        **   **+**    **        |            |
                        ****************        |            |
                                ^               |            |
                                |             *******************
                                +-------------** ptr **+** A   **
                                              **     **+**     **<== pointer
                                              *******************
*/

//add num1 and num2 store value in num1
void sum(int *num1, int *num2);

int main(){

    int n=10;

    printf("The value of n is : %d\n", n);
    printf("The adress of n is : %p\n", &n);

    //introducing the pointer variable
    // syntax for declaration is type_t &variable_name;
    int *ptr;

    //syntax for initialization is variable_name=&variable_name(must be of same tpe as pointer or void)
    ptr=&n;//stores the adress of n (&n)
    
    printf("The value of ptr is: %p\n", ptr);//same as the adress of n
    printf("The adress of ptr is: %p\n", &ptr);//adress of pointer variable


    //we can use deferencing to access the value of n through the pointer variable
    int val = *ptr;

    printf("The value of n from ptr is %d\n", val) ;//same as n
    
    printf("The value of n from ptr is %d\n", *ptr) ;//shorthand

    // after using them we must free pointers can be done by initializing them by NULL
    ptr=NULL;


    //using a pointer to store value of another pointer
    int v1=12 ;//, v2=14;

    int *ptr1; int *ptr2;
    //ptr2 -> ptr1 -> &{v1}
    ptr1=&v1;

    ptr2=ptr1;
    printf("Element in ptr1 is %d\n",*ptr1);//point to same element
    printf("Element in ptr2 is %d\n",*ptr2);

    printf("Adress stored @ Ptr1 : %p\n", ptr1);
    printf("Adress stored @ Ptr1 : %p\n", ptr1);

    printf("Ptr1@_%p\n", &ptr1);
    printf("Ptr2@_%p\n", &ptr2);

    //using a pointer to manipulate a variables value
    int a=20, b=45;
    printf("before a:%d, b:%d\n",a,b);
    
    sum(&a, &b);//passing elements by reference

    printf("after a:%d, b:%d\n",a,b);//a store the sum of (20+45)
    
    return 0;
}

void sum(int *num1, int * num2){
    *num1= (*num1+*num2);
}