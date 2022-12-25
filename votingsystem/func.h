#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int findUser();


void printMenu_0(){

	printf("Press : \n");
	printf("1. Log in\n");
	printf("2. Register\n");
	printf("0. Quit");
}

void LoginUser(){

	char tempid[2],pwd[10];

	printf("\tEnter ID : ");
	scanf("%s",tempid);

	int fd=open("users",O_RDONLY);

	char temp[2];

	//printf("->%s\n",temp);

	read(fd,temp,2);

	printf("->%s\n",temp);

	int ct = 11;

	while(ct<=36){

		lseek(fd,11,SEEK_CUR);

		read(fd,temp,2);

        	printf("->%s \t %d\n",temp,strlen(temp));
		printf("\t%c,%c\n",temp[0],temp[1]);
		strcat(temp[0],temp[1]);
		ct+=11;
	}



	/*while(strcmp(tempid,temp) != 0 && count<= 48){

		count += 13;

		pos=lseek(fd,count,SEEK_END);

		read(fd,temp,2);

		printf("%d->[%d]: %s\n",pos,count,temp);

		if(strcmp(tempid,temp)==0) { printf("pos : %d\n",pos); break;}

	}*/
}
