/*
					#################################################################################
					######################## Wrote and Compiled by ##################################
					#############################  Brian Kidiga  ####################################
					#################################################################################
					######################        Github  @      ####################################
					##################    github.com/la-mello    ####################################
					#################################################################################
					#################################################################################
					########################### CopyRight (22)   ####################################
					#################################################################################
					#################################################################################



*/





#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>



#define MAX_LENGTH 150

int flag =1;

int key=2022;

int msgtorec=0;

struct msg{
	long int type;
	char data[MAX_LENGTH];
};

struct msg_log{
	long int id;
	char data[MAX_LENGTH];
};

void welcome(){
	printf("\t********************************\n");
	printf("\t****** Welcome to chatspot *****\n");
	printf("\t********************************\n");
}

void bye(){
        printf("\t********************************\n");
        printf("\t***** Goodbye from chatspot ****\n");
        printf("\t********************************\n");
}

int checkexit(struct msg bubble){

	if(strncmp(bubble.data,"end",3) == 0)
                return 0;
	else
		return 1;
}

void endChat(int q_id){
	bye();
	msgctl(q_id,IPC_RMID,0);
}


void logs(struct msg bbl,int q_id){
	//open a log file in append and wronly mode
	//create file if doesnt exist
	int fd = open("logs",O_CREAT|O_RDWR|O_APPEND);

	//printf("Opened log file [%d]\n",fd);

	if(fd<1){
		printf("Error collecting logs\n");
		sleep(1);
		endChat(q_id);
		exit(1);
	}

	write(fd,bbl.data,strlen(bbl.data));
}

//void write_struct(struct )

void defLogs(char msg[]){
	int fd = open("logs",O_CREAT|O_APPEND,0666);
	write(fd,msg,strlen(msg));
}

