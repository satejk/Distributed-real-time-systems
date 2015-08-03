//satej khandeparkar
/*
 * This file is part of my Distributed real time systems project.
 *
 * related to the study of message queues as a better IPC for distributed
 *  systems.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc.

 *
 * This file is intended for education purpose only.
 */


#include<sys/types.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 128


void die(char* s){

	perror(s);
	exit(1);

}





struct msgbuf {

	long mtype;

	char mtext[MAXSIZE];

};


main(){
	
	int msqid;

	int msgflg = IPC_CREAT | 0666;


	key_t key;

	struct msgbuf sbuf;

	size_t buflen;

	key = 1234;

	//get the mesg queue ID for the given key
	if ((msqid = msgget(key,msgflg)) < 0){
		
		die("msgget");
	
	} 



	sbuf.mtype = 1;


	printf("Enter a message to add to message queue : ");

	scanf("%[^\n]",sbuf.mtext);

	getchar();

	buflen = strlen(sbuf.mtext) + 1;

	if( msgsnd(msqid , &sbuf , buflen , IPC_NOWAIT) < 0){

		printf(" %d , %ld , %s, %zu \n",msqid,sbuf.mtype,sbuf.mtext, buflen);

		die("msgsnd");
	}
	else{

		printf("Message Sent \n");
	
		exit(0);



	}




}

