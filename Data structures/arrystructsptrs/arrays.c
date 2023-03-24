#include<stdio.h>

/**
    store data of the same type in an contigous block of memory

    type_t array <= stores => type_t elements

    the size of an array is fixed and allocated during declaration (it cannot be changed/ the array cant grow)

    ( size_t * type_t )sized array stores ( size_t / type_t ) elements

    int nums[4];

    stored in contigous memory locations( adjascent to each other )

      nums       [0]      [1]        [2]        [3]
    +=======+-----------------------------------------+
    + 0xndl + 0xndl   | 0xndl+1  | 0xndl+2 | 0xndl+3  |
    +=======+-----------------------------------------+

    elements of one type and can be accessed by indexes
      nums   [0]  [1]  [2]  [3]
    +=======+------------------+
    + 0xndl + 1  | 2  | 3  | 4 |
    +=======+------------------+

*/


// a method to print an integer array of size len
void print_arry(int nums[], int len){
    printf("array_@_%p [ ", &nums);
    for(int i=0; i<len; i++)
        printf("%d ", nums[i]);
    printf("]\n");
    fflush(stdout);
}


//pointers and arrays
void print_arry_ptr(int *ptr, int len){
    int counter=0;
    printf("array_@_%p [ ",ptr);

    for(int i=0; i<len; i++){
            printf("%d ",*(ptr+i));
    }
    printf("]\n");
}

int main(){

    //first way of declaring and initializing an array
    int nums[5];
    nums[0]=1; nums[1]=2; nums[2]=3; nums[3]=4; nums[4]=5;
    print_arry(nums, 5);

    int nums2 [] = {6,7,8,9,10};
    print_arry(nums2,5);

    int *ptr=nums2;
    print_arry_ptr(ptr, 5);

    return 0;
}