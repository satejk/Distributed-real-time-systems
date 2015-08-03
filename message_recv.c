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

#include <sys/types.h>
#include<sys/ipc.h>

#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 128


void die(char *s){


	perror(s);
	exit(1);	

}


typedef struct msgbuf 
{

	long mtype;

	char mtext[MAXSIZE];


}msgbuf;


main(){



	int msqid;

	key_t key;

	msgbuf rcvbuffer;



	key = 1234;
	
	if( (msqid = msgget(key, 0666)) < 0){

		die("msgget");


	}


	//recieve an answer of message type 1

	if (msgrcv(msqid, &rcvbuffer , MAXSIZE, 1,0) < 0){

		die("msgrcv");

		
	}

	printf("%s \n",rcvbuffer.mtext);

	exit(0);


}


























