#include "headers.h"

int main(){

	int q_id;

	char buf[150];

	char logtitle[200];

	struct msg bubble;

	//create message queue
	q_id = msgget((key_t)key, 0666|IPC_CREAT);

	welcome();

	printf("\n\tServer with id [%d] created\n",q_id);

	strcpy(logtitle,"\n\tWelcome to Todays Logs created chat\n\n");

	defLogs(logtitle);

	int i=0;
	//enter chat loop
	while(flag){

		printf("[%d] Send :",i);

		//read text from users
		fgets(buf,150,stdin);

		//create bubble
		bubble.type=1;
		strcpy(bubble.data,buf);

		logs(bubble,q_id);//collecting logs for host

		if(msgsnd(q_id, (void *)&bubble, MAX_LENGTH, 0) == -1){
			printf("Error sending message : restart server");
			//msgctl(q_id,0)
		}

		i++;

		flag=checkexit(bubble);//checking if host terminater chat

		if(flag != 0){

			printf("\tWaiting for reply.....\n");

			msgrcv(q_id, (void *)&bubble ,MAX_LENGTH,msgtorec,0);

                	printf("[%d] Reply : %s\n",i,bubble.data);

			logs(bubble,q_id);//collecting logs for host

			flag=checkexit(bubble);//checking if client exist chat

			i++;
		}else
			break;

	}

	printf("\tServer terminated with [%d] chats\n",i);

	endChat(q_id);

return 0;
}


