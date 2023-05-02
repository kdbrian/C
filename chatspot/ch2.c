#include "headers.h"

int main(){

	int q_id;

	char buf[150];

	struct msg bubble;

	//create message queue
	q_id = msgget((key_t)key, 0666|IPC_CREAT);

	welcome();

	printf("\n\tConnected to Server\n");

	printf("\nWait for message from host\n");

	int i=0;
	//enter chat loop
	while(flag){

		//recieve message first
		msgrcv(q_id, (void *)&bubble ,MAX_LENGTH,msgtorec,0);

                printf("[%d] Reply : %s\n",i,bubble.data);

		printf("[%d] Send :",i);

                //read text from users
                fgets(buf,150,stdin);

                //create bubble
                bubble.type=1;
                strcpy(bubble.data,buf);

                if(msgsnd(q_id, (void *)&bubble, MAX_LENGTH, 0) == -1){
                        printf("Error sending message : restart server\n");
                        //msgctl(q_id,0)
                }

                printf("\tWaiting for reply.....\n");

		flag=checkexit(bubble);

		i++;

	}

	bye();

return 0;
}


