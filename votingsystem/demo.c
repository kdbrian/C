#include<stdio.h>
#include<unistd.h>

#include "func.h"//contains all our functions and variables


int main(){

	printMenu_0();

	int choice ;

	printf("\t:-");
	scanf("%d",&choice);



	switch(choice){

		case 1://login
			LoginUser();
			break;

		case 2://register
			//registerUser();
			break;

		case 3://system stat
			//sys_report();
			break;

		case 0:
			printf("Login out.");
			printf("\n");
			break;

		default:
			break;

	}

//	footer();

return 0;
}

