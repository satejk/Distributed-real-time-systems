#include<stdio.h>
#include "mesg.h"
#include <stdlib.h>
#include<string.h>


Mesg mesg;


void server(int ipcreadfd, int ipcwritefd){


	int n , filefd;

	char errmesg[256];

	

	mesg.mesg_type = 1L;

	if((n = mesg_recv(ipcreadfd,&mesg)) <=0 ){

		printf("server: filename read error  \n");

	}


	mesg.mesg_data[n] = '\0'; //null terminate filename


	
	//error send error mesg to client
	if((filefd = open(mesg.mesg_data,0)) < 0 ){

		printf("filefd  = %d \n ", filefd);

		sprintf(errmesg, ": can't open the file.\n");
		strcat(mesg.mesg_data, errmesg);
	
		mesg.mesg_len = strlen(mesg.mesg_data);
		mesg_send(ipcwritefd, &mesg);

	} 
	else{

		while((n = read(filefd, mesg.mesg_data,MAXMESGDATA)) > 0){

			mesg.mesg_len = n;

			mesg_send(ipcwritefd,&mesg);


		}
		close(filefd);

		if(n< 0) printf("server: read error");

	}

	// send a message with a length of 0 to signify end

	mesg.mesg_len = 0;

	mesg_send(ipcwritefd, &mesg);


}











