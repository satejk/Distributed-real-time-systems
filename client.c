#include<stdio.h>
#include<string.h>

#include "mesg.h"


Mesg mesg;



void client( int ipcreadfd, int ipcwritefd){

	int n;


	//read the filename from the std input , and write as a   
	// message to IPC descriptor

	if(fgets(mesg.mesg_data, MAXMESGDATA,stdin) == NULL){


		printf("filename read error");

	}

	printf("%s",mesg.mesg_data);
	n = strlen(mesg.mesg_data);

	if(mesg.mesg_data[n-1] == '\n'){


		n--;

		mesg.mesg_len = n;
		mesg.mesg_type = 1L;


		mesg_send(ipcwritefd, &mesg );



	} 



	while(( n = mesg_recv(ipcreadfd, &mesg) ) > 0){

		if(write(1, mesg.mesg_data) != n){
				
				printf("data write error");

			}




	}


	if(n < 0) printf("data read error");




}
