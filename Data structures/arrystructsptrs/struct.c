#include<stdio.h>
#include<string.h>
/*
        struct are datatypes that can contain other types
        generally composed of different types
        
                        +-----------------------+
                        *----- -  Struct  ------*
                        *---- -struct_name------*
                        +=======================+
                        |  type_t member1;      |
                        |  type_t member2;      |
                        |           .           |
                        |           .           |
                        |  type_t membern;      |
                        +-----------------------+
                        
*/

//can be declared globally
struct user_details{
    char Username[20];
    char password[12];
}user1;

//another way of creating a struct
typedef struct{
    int code;
    char initials[5];//struct members can be arrays
}country;



//a str can have another struct as an element
typedef struct{
    
    struct user_details user;
    
    //can nest the struct
    struct adress{
        char location[15];
        char zip_code[7];
        char phone[13];
    }user_adress;

    //or declare separately
    country user_country;
}user_v2;


struct user_v2;

void print_user(user_v2 *usr);

int main(){

    //to create a new struct //user1 was already globally declared
    strcpy(user1.Username, "junrdev");
    strcpy(user1.password, "junrdev1234");

    printf("User1 : @_%p\n", &user1);
    printf("User1 : username => %s\n", user1.Username);
    printf("User1 : password => %s\n", user1.password);
    
    //size of struct is as a result of the summation of the sizes of its children
    printf("User1 : size_in_mem  => %d\n", sizeof(user1));

    printf("\n");


    //can be created locally
    struct adress2{
        char location[15];
        char zip_code[7];
        char phone[13];
    };

    // second way of declaring and initializing the struct
    struct adress2 my_adress;
    strcpy(my_adress.location,"Nairobi, Kenya");
    strcpy(my_adress.zip_code,"31-0100");
    strcpy(my_adress.phone,"+25471930245");

    printf("Adress : @_%p\n", &my_adress);
    printf("Adress/phone : %s\n", my_adress.phone);
    printf("Adress/location : %s\n", my_adress.location);
    printf("Adress/zip_code : %s\n", my_adress.zip_code);

    printf("\n");
    //declaration from the struct with typedef allows us to loose the struct K.W while  declaration
    country Kenya;
    Kenya.code=254;
    strcpy(Kenya.initials,"KE");
    printf("Country@_%p\n", &Kenya);
    printf("Country : Code %d\n", Kenya.code);
    printf("Country : Init %s\n", Kenya.initials);

  
    // introducing pointers to structs
    user_v2 enstein_brains;
    user_v2 * user_ptr = &enstein_brains;

    strcpy(user_ptr->user.Username,"enstein_brains");
    strcpy(enstein_brains.user.password,"albert1234");

    strcpy(enstein_brains.user_adress.location,"location 58");
    strcpy(enstein_brains.user_adress.zip_code,"31-0100");
    strcpy(enstein_brains.user_adress.phone,"+25471930245");
    
    enstein_brains.user_country.code=254;
    strcpy(enstein_brains.user_country.initials,"KE");

    print_user(&enstein_brains);

    return 0;
}

void print_user(user_v2 * user_ptr){

    printf("\nUser@_%p\n", user_ptr);
    printf("User.details : {%s, %s}\n", user_ptr->user.Username, user_ptr->user.password);
    printf("User.adress : {%s, %s, %s}\n", user_ptr->user_adress.location, user_ptr->user_adress.zip_code, user_ptr->user_adress.phone);
    printf("User.country: {%s, %d}\n", user_ptr->user_country.initials, user_ptr->user_country.code);

}