#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<stdbool.h>
#include "calcLib.h"
#include "calcLib.c"

#define MAX 200
#define PORT 7500
#define SA struct sockaddr



char buffer[MAX];
char val1[10];
char val2[10];
char rval[10];
pid_t childpid;
// function that performs calculations



void func(int sockfd)
{
     char text[20] = "TEXT TCP 1.0\n";
     if (write(sockfd,text, sizeof(text)) < 0){
       printf("Error writing to client\n");
       }
       bzero(text, sizeof(text));

     bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
      printf("Client responded with: %s\n", buffer);

  initCalcLib();
  char *ptr;
  ptr=randomType(); // Get a random arithemtic operator.

  double f1,f2,fresult;
  int i1,i2,iresult;
  char msg[] = "OK\n";
  char msg1[] = "ERROR\n";
  /*
  printf("ptr = %p, \t", ptr );
  printf("string = %s, \n", ptr );
  */

  /* Act differently depending on what operator you got, judge type by first char in string. If 'f' then a float */

  if(ptr[0]=='f'){
    //printf("Float\t");
    f1=randomFloat();
    f2=randomFloat();

    /* At this point, ptr holds operator, f1 and f2 the operands. Now we work to determine the reference result. */

    if(strcmp(ptr,"fadd")==0){
      fresult=f1+f2;
      //sprintf(rval, "%d", iresult);
            sprintf(val1, "%f",f1);
            printf("val1 is : %s\n", val1);
            sprintf(val2, "%f",f2);
            printf("val2 is : %s\n", val2);
            strcpy(buffer, "fadd");
            //buffer[sizeof buffer - 1] = '\0';
            strcat(buffer, " ");
            strcat(buffer,val1);
            strcat(buffer, " ");
            strcat(buffer,val2);
            printf("Back to client: %s\n",buffer);

                  //write(sockfd, res, sizeof(res));
            if (write(sockfd, buffer, sizeof(buffer)) < 0){
             printf("Error writing to client\n");
             }
             bzero(buffer, sizeof(buffer));
             if (read(sockfd, buffer, sizeof(buffer)) < 0){
             error("ERROR reading from socket");
             }
             float result = atof(buffer);
            printf(" Answer from client: %s\n",buffer);
            printf(" converted integer: %f\n",result);
            if (abs(fresult- result) < 0.01){

            bzero(buffer, sizeof(buffer));

            write(sockfd, msg, sizeof(msg));
            bzero(msg, sizeof(msg));
            //break;
            }
            else{
            write(sockfd, msg1, sizeof(msg1));
            bzero(msg1, sizeof(msg1));
            }

    } else if (strcmp(ptr, "fsub")==0){
      fresult=f1-f2;
      sprintf(val1, "%f",f1);
      printf("val1 is : %s\n", val1);
      sprintf(val2, "%f",f2);
      printf("val2 is : %s\n", val2);
      strcpy(buffer, "fsub");
      //buffer[sizeof buffer - 1] = '\0';
      strcat(buffer, " ");
      strcat(buffer,val1);
      strcat(buffer, " ");
      strcat(buffer,val2);
      printf("Back to client: %s\n",buffer);

            //write(sockfd, res, sizeof(res));
      if (write(sockfd, buffer, sizeof(buffer)) < 0){
       printf("Error writing to client\n");
       }
       bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
       float result = atof(buffer);
      printf(" Answer from client: %s\n",buffer);
      printf(" converted integer: %f\n",result);
      if (abs(fresult- result) < 0.01){

      bzero(buffer, sizeof(buffer));

      write(sockfd, msg, sizeof(msg));
      bzero(msg, sizeof(msg));
      //break;
      }
      else{
      write(sockfd, msg1, sizeof(msg1));
      bzero(msg1, sizeof(msg1));
      }

    } else if (strcmp(ptr, "fmul")==0){
      fresult=f1*f2;
      sprintf(val1, "%f",f1);
      printf("val1 is : %s\n", val1);
      sprintf(val2, "%f",f2);
      printf("val2 is : %s\n", val2);
      strcpy(buffer, "fmul");
      //buffer[sizeof buffer - 1] = '\0';
      strcat(buffer, " ");
      strcat(buffer,val1);
      strcat(buffer, " ");
      strcat(buffer,val2);
      printf("Back to client: %s\n",buffer);

            //write(sockfd, res, sizeof(res));
      if (write(sockfd, buffer, sizeof(buffer)) < 0){
       printf("Error writing to client\n");
       }
       bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
       float result = atof(buffer);
      printf(" Answer from client: %s\n",buffer);
      printf(" converted integer: %f\n",result);
      if (abs(fresult- result) < 0.01){

      bzero(buffer, sizeof(buffer));

      write(sockfd, msg, sizeof(msg));
      bzero(msg, sizeof(msg));
      //break;
      }
      else{
      write(sockfd, msg1, sizeof(msg1));
      bzero(msg1, sizeof(msg1));
      }

    } else if (strcmp(ptr, "fdiv")==0){
      fresult=f1/f2;
      sprintf(val1, "%f",f1);
      printf("val1 is : %s\n", val1);
      sprintf(val2, "%f",f2);
      printf("val2 is : %s\n", val2);
      strcpy(buffer, "fdiv");
      //buffer[sizeof buffer - 1] = '\0';
      strcat(buffer, " ");
      strcat(buffer,val1);
      strcat(buffer, " ");
      strcat(buffer,val2);
      printf("Back to client: %s\n",buffer);

            //write(sockfd, res, sizeof(res));
      if (write(sockfd, buffer, sizeof(buffer)) < 0){
       printf("Error writing to client\n");
       }
       bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
       float result = atof(buffer);
      printf(" Answer from client: %s\n",buffer);
      printf(" converted integer: %f\n",result);
      if (abs(fresult- result) < 0.01){

      bzero(buffer, sizeof(buffer));

      write(sockfd, msg, sizeof(msg));
      bzero(msg, sizeof(msg));
      //break;
      }
      else{
      write(sockfd, msg1, sizeof(msg1));
      bzero(msg1, sizeof(msg1));
      }

    }
   // printf("%s %8.8g %8.8g = %8.8g\n",ptr,f1,f2,fresult);
  } else {
    //printf("Int\t");
    i1=randomInt();
    i2=randomInt();

    if(strcmp(ptr,"add")==0){
      iresult=i1+i2;
      //sprintf(rval, "%d", iresult);
      sprintf(val1, "%d",i1);
      printf("val1 is : %s\n", val1);
      sprintf(val2, "%d",i2);
      printf("val2 is : %s\n", val2);
      strcpy(buffer, "add");
      //buffer[sizeof buffer - 1] = '\0';
      strcat(buffer, " ");
      strcat(buffer,val1);
      strcat(buffer, " ");
      strcat(buffer,val2);
      printf("Back to client: %s\n",buffer);

            //write(sockfd, res, sizeof(res));
      if (write(sockfd, buffer, sizeof(buffer)) < 0){
       printf("Error writing to client\n");
       }
       bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
       int result = atoi(buffer);
      printf(" Answer from client: %s\n",buffer);
      printf(" converted integer: %d\n",result);
      if (abs(iresult- result) < 0.01){

      bzero(buffer, sizeof(buffer));

      write(sockfd, msg, sizeof(msg));
      bzero(msg, sizeof(msg));
      //break;
      }
      else{
      write(sockfd, msg1, sizeof(msg1));
      bzero(msg1, sizeof(msg1));

      }
    } else if (strcmp(ptr, "sub")==0){
      iresult=i1-i2;

      sprintf(val1, "%d",i1);
      printf("val1 is : %s\n", val1);
      sprintf(val2, "%d",i2);
      printf("val2 is : %s\n", val2);
      strcpy(buffer, "sub");
      //buffer[sizeof buffer - 1] = '\0';
      strcat(buffer, " ");
      strcat(buffer,val1);
      strcat(buffer, " ");
      strcat(buffer,val2);
      printf("Back to client: %s\n",buffer);

            //write(sockfd, res, sizeof(res));
      if (write(sockfd, buffer, sizeof(buffer)) < 0){
       printf("Error writing to client\n");
       }
       bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
       int result = atoi(buffer);
      printf(" Answer from client: %s\n",buffer);
      printf(" converted integer: %d\n",result);
      if (abs(iresult- result) < 0.01){

      bzero(buffer, sizeof(buffer));

      write(sockfd, msg, sizeof(msg));
      bzero(msg, sizeof(msg));
      //break;
      }
      else{
      write(sockfd, msg1, sizeof(msg1));
      bzero(msg1, sizeof(msg1));

      }

    } else if (strcmp(ptr, "mul")==0){
      iresult=i1*i2;

      sprintf(val1, "%d",i1);
      printf("val1 is : %s\n", val1);
      sprintf(val2, "%d",i2);
      printf("val2 is : %s\n", val2);
      strcpy(buffer, "mul");
      //buffer[sizeof buffer - 1] = '\0';
      strcat(buffer, " ");
      strcat(buffer,val1);
      strcat(buffer, " ");
      strcat(buffer,val2);
      printf("Back to client: %s\n",buffer);

            //write(sockfd, res, sizeof(res));
      if (write(sockfd, buffer, sizeof(buffer)) < 0){
       printf("Error writing to client\n");
       }
       bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
       int result = atoi(buffer);
      printf(" Answer from client: %s\n",buffer);
      printf(" converted integer: %d\n",result);
      if (abs(iresult- result) < 0.01){

      bzero(buffer, sizeof(buffer));

      write(sockfd, msg, sizeof(msg));
      bzero(msg, sizeof(msg));
      //break;
      }
      else{
      write(sockfd, msg1, sizeof(msg1));
      bzero(msg1, sizeof(msg1));

      }

    } else if (strcmp(ptr, "div")==0){
      iresult=i1/i2;

      sprintf(val1, "%d",i1);
      printf("val1 is : %s\n", val1);
      sprintf(val2, "%d",i2);
      printf("val2 is : %s\n", val2);
      strcpy(buffer, "div");
      //buffer[sizeof buffer - 1] = '\0';
      strcat(buffer, " ");
      strcat(buffer,val1);
      strcat(buffer, " ");
      strcat(buffer,val2);
      printf("Back to client: %s\n",buffer);

            //write(sockfd, res, sizeof(res));
      if (write(sockfd, buffer, sizeof(buffer)) < 0){
       printf("Error writing to client\n");
       }
       bzero(buffer, sizeof(buffer));
       if (read(sockfd, buffer, sizeof(buffer)) < 0){
       error("ERROR reading from socket");
       }
       int result = atoi(buffer);
      printf(" Answer from client: %s\n",buffer);
      printf(" converted integer: %d\n",result);
      if (abs(iresult- result) < 0.01){

      bzero(buffer, sizeof(buffer));

      write(sockfd, msg, sizeof(msg));
      bzero(msg, sizeof(msg));
      //break;
      }
      else{
      write(sockfd, msg1, sizeof(msg1));
      bzero(msg1, sizeof(msg1));

      }
    }

   // printf("%s %d %d = %d \n",ptr,i1,i2,iresult);
  }
  }


int main()
{
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
        for (;;) {
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
        printf("server acccept the client...\n");
        if ((childpid = fork()) == 0) {
        close(sockfd); 
        for (;;) {
     
        
	// Function for chatting between client and server
	func(connfd);
	//char text[5] = "OK\n";
		//char text[5] = "OK\n";

        }
        }

	// After chatting close the socket
	 close(connfd);
	 }
}

