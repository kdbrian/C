//headers
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

void flush_arry();

//to decorate the output
void decorate(){
	printf("\t******************\n");
}

//prints the default menu on start up
void printMenu_0(){
	decorate();
	printf("\nWelcome to the Online Voting System\n");
	decorate();
	printf("\n\tPress :\n");
	printf("\t1.Login\n");
	printf("\t2.Register\n");
	printf("\t3.Check System status\n");
	printf("\t0. Quit\n");
}

void printMenu_1(){

}

//user will login with id and password
//id will be two integers long and password 10 characters wide;

void loginUser(){

	char tempid[3],pwdu[10],uid[3];

	printf("\tEnter user id : ");
	scanf("%s",&tempid);

	printf("Entered:\n\t tempID - %s\n",tempid);

	/*
	printf("\n\tEnter password : ");
	scanf("%s",&pwdu);

	printf("pwd - %s\n",pwdu);
	*/
}

void registerUser(){
}

void sys_report(){
}

void printResult(){
	printf("result func");
}

void writeFile(){
	printf("file writer");
}

void footer(){
	decorate();
	printf("\t*****By brian*****\n");
	decorate();
}
