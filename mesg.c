

//#include </home/satej/Documents/cprograms/project_firestorm/mesg.h>
#include "mesg.h"
#include <stdlib.h>
#include <stdio.h>

//#include <sys/types.h>
#include<sys/ipc.h>

#include<sys/msg.h>



//send a message using message queue
void mesg_send(int id,Mesg *mesgptr){


	//send the messsage - type followed by data

	if(msgsnd(id, (char*)&(mesgptr->mesg_type),mesgptr->mesg_len,0) != 0){

			printf("message send error \n");

		}



}


//recieve a message from a message queue

int mesg_recv(int id , Mesg *mesgptr){


	int n;


	n = msgrcv(id ,(char *)&(mesgptr->mesg_type),MAXMESGDATA,mesgptr->mesg_type,0);


	if((mesgptr -> mesg_len = n) < 0){

		printf(" recieve error \n");

	}




	return n;

}





