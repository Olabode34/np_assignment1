#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <stdbool.h>
#define MAX 80 
#define PORT 7500 

#define SA struct sockaddr 



void error(const char *msg)
{
    perror(msg);
    exit(0);
}



 void func(int sockfd){
 
 
/*    char str[100];*/
/*    char buff[MAX]; */
/*	int n;*/
/*	read(sockfd, &buff, sizeof(buff)); */
/*	*/
/*        //ans = atoi(read(sockfd, result, sizeof(result))); */
/*        printf("From Server : %s\n", buff);*/
/*        bzero(buff, sizeof(buff));  */
/*      */
/*	printf("Enter Reply to Server :\n");*/
/*        */
/*        while ((buff[n++] = getchar()) != '\n') */
/*            ; */
/*  */
/*        // and send that buffer to client */
/*        write(sockfd, buff, sizeof(buff)); */
/*      */
/*           // char msg[5] = "OK";*/
/*          */
/*           // write(sockfd, msg, sizeof(msg)); */
/*           // bzero(msg, sizeof(msg)); */
/*	//printf("From Server : %d  \n",*result ); */
/*	bzero(buff, sizeof(buff));  */
/*	//recv(sockfd, &buff, sizeof(buff), 0);*/

/*     */
    
    
    
    
    
 
    char str[255];
    char splitStrings[10][10]; //can store 10 words of 10 characters
    int i,j,cnt;
    int dnum1,dnum2;
    float fnum1,fnum2;
   // char operator[10];
    int number_to_send;
    int converted_number;
    float float_to_send;
    float float_converted;
    char st[80];
    char slash[5] = "\\n";
    char final[20];
  //  printf("Enter a string: ");
 //   gets(str);
    for(;;)
    {
    
    
    
    
    read(sockfd, str, sizeof(str)); 
	
        //ans = atoi(read(sockfd, result, sizeof(result))); 
        printf("From Server : %s\n", str);
        bzero(str, sizeof(str));  
      
/*	printf("Enter Reply to Server :\n");*/
/*        */
/*        while ((buff[n++] = getchar()) != '\n') */
/*            ; */
/*  */
/*        // and send that buffer to client */
/*        write(sockfd,Your Earnings
 buff, sizeof(buff)); */
      
            char msg[5] = "OK\n";
          
          write(sockfd, msg, sizeof(msg)); 
          bzero(msg, sizeof(msg)); 
	//printf("From Server : %d  \n",*result ); 
	//(buff, sizeof(buff));  
	//recv(sockfd, &buff, sizeof(buff), 0);

      // read(sockfd, buff, sizeof(buff)); 
       
       //printf("Opertion from server : %s\n", buff);
    
    
    
    
    read(sockfd, str, sizeof(str)); 
    
    //printf("Opertion from server : %s\n", str);
    
    j=0; cnt=0;
    for(i=0;i<=(strlen(str));i++)
    {
        // if space or NULL found, assign NULL into splitStrings[cnt]
        if(str[i]==' '||str[i]=='\0')
        {
            splitStrings[cnt][j]='\0';
            cnt++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            splitStrings[cnt][j]=str[i];
            j++;
        }
    }
   // printf("\nOriginal String is: %s",str);
   // printf("\nStrings (words) after split by space:\n");
    
   // printf("number of words: %s \n",splitStrings[1]);
    for(i=0;i < cnt;i++)
        //operator= splitStrings[0];
        dnum1 = atoi(splitStrings[1]);
        dnum2 = atoi(splitStrings[2]);
        
        fnum1 = atof(splitStrings[1]);
        fnum2 = atof(splitStrings[2]);
       // printf("fnum1: %f \n",fnum1);
       // printf("fnum2: %f \n",fnum2);
        //printf("Operator: %s \n",operator);
        //printf("num1: %.2f \n",num1);
        //printf("num2: %.2f \n",num2);
        //printf("num1: %d\n",num1);
       // printf("num2: %d\n",num2);
        if ((strcmp(splitStrings[0],"add")) == 0){
            number_to_send = dnum1 + dnum2;
             // Put your value
             //char st[20];
            bzero(st, sizeof(st)); 
            
            sprintf(st, "%d", number_to_send);
            //converted_number = htonl(number_to_send);
            strcat(st,"\n");
            printf("From Server: %s\n", str); 
           
	    //char re[5] = "0.0001\n";
            //strcat(st, slash);
            
            if (write(sockfd, st, sizeof(st)) < 0)
                 error("ERROR writing to socket");
            printf("Answer back to server: %s\n",st);
            bzero(str, sizeof(str)); 
            
            if (read(sockfd, final, sizeof(final)) < 0) 
                 error("ERROR reading from socket");
    
    
    
            
             //read(sockfd, str, sizeof(str)); 
             printf("Responds from Server : %s\n",final);
             break;
            }
            
        if ((strcmp(splitStrings[0],"div")) == 0){
            number_to_send = dnum1/dnum2; // Put your value
             bzero(st, sizeof(st)); 
             sprintf(st, "%d", number_to_send);
            //converted_number = htonl(number_to_send);
            printf("From Server: %s\n", str); 
          
            strcat(st,"\n");
            printf("Answer back to server: %s\n",st);
            //write(sockfd, st, sizeof(st));
            if (write(sockfd, st, sizeof(st)) < 0)
            printf("Error writing to server\n");
            
              bzero(str, sizeof(str)); 
            // read(sockfd, str, sizeof(str));
           // printf("Responds Server : "); 
            if (read(sockfd, str, sizeof(str)) < 0){
             error("ERROR reading from socket");
            } 
            printf("Responds Server : %s\n", str);
            break;
            }
/*            converted_number = htonl(number_to_send);*/
/*            printf("From server: %s\n", str); */
/*            printf("Answer back to server: %d\n",number_to_send);*/
/*            write(sockfd, &converted_number, sizeof(converted_number));*/
            
        
        if ((strcmp(splitStrings[0],"mul")) == 0){
            number_to_send = dnum1*dnum2; // Put your value
            bzero(st, sizeof(st)); 
             sprintf(st, "%d", number_to_send);
            //converted_number = htonl(number_to_send);
            printf("From Server: %s\n", str); 
           
            strcat(st,"\n");
            //char res[10] = "0.0001\n";
            //printf("Answer back to server: %s\n",res);
            printf("Answer back to server: %s\n",st);
           
            //write(sockfd, res, sizeof(res));
            if (write(sockfd, st, sizeof(st)) < 0)
            printf("Error writing to server\n");
            
            bzero(str, sizeof(str)); 
            if (read(sockfd, str, sizeof(str)) < 0){
             error("ERROR reading from socket");
            } 
            printf("Responded Server : %s\n",str);
            
             break;
            //printf("Responds Server : %s\n", str);
            
            }
            
/*            converted_number = htonl(number_to_send);*/
/*            printf("From server: %s\n", str); */
/*            printf("Answer back to server: %d\n",number_to_send);*/
/*            write(sockfd, &converted_number, sizeof(converted_number));*/
            
            
        if ((strcmp(splitStrings[0],"sub")) == 0){
            number_to_send = dnum1-dnum2; // Put your value
            bzero(st, sizeof(st)); 
             sprintf(st, "%d", number_to_send);
            //converted_number = htonl(number_to_send);
            printf("From Server: %s\n", str); 
           
            strcat(st,"\n");
            printf("Answer back to server: %s\n",st);
            //write(sockfd, st, sizeof(st));
            if (write(sockfd, st, sizeof(st)) < 0)
            printf("Error writing to server\n");
            
            bzero(str, sizeof(str)); 
            //read(sockfd, str, sizeof(str)); 
            if (read(sockfd, str, sizeof(str)) < 0){
             error("ERROR reading from socket");
            } 
             //printf("Responds Server : ");
            printf("Responds Server : %s\n", str);
            break;
            
            }
/*            converted_number = htonl(number_to_send);*/
/*            printf("From server: %s\n", str); */
/*            printf("Answer back to server: %d\n",number_to_send);*/
/*            write(sockfd, &converted_number, sizeof(converted_number));*/
            
        
        
        if ((strcmp(splitStrings[0],"fadd")) == 0){
            float_to_send = fnum1 + fnum2; // Put your value
            bzero(st, sizeof(st)); 
             sprintf(st, "%f", float_to_send);
            //converted_number = htonl(number_to_send);
            printf("From Server: %s\n", str); 
           
            strcat(st,"\n");
            printf("Answer back to server: %s\n",st);
            if (write(sockfd, st, sizeof(st)) < 0)
            printf("Error writing to server\n");
            bzero(str, sizeof(str)); 
             //read(sockfd, str, sizeof(str)); 
              //printf("Responds Server : ");
             if (read(sockfd, str, sizeof(str)) < 0){
             error("ERROR reading from socket");
            } 
            printf("Responds Server : %s\n", str);
            break;
            
            }
/*            printf("From server: %s\n", str); */
/*            printf("Answer back to server: %f\n",float_to_send);*/
/*            send(sockfd, &float_to_send, sizeof(float_to_send), 0);*/
            //}
            //write(sockfd, &float_converted, sizeof(float_to_send));}
            
        if ((strcmp(splitStrings[0],"fdiv")) == 0){
            float_to_send = fnum1/fnum2; // Put your value
            bzero(st, sizeof(st)); 
            sprintf(st, "%f", float_to_send);
            //converted_number = htonl(number_to_send);
            printf("From Server: %s\n", str); 
           
            strcat(st,"\n");
            printf("Answer back to server: %s\n",st);
            //write(sockfd, st, sizeof(st));
            if (write(sockfd, st, sizeof(st)) < 0)
            printf("Error writing to server\n");
            
            bzero(str, sizeof(str)); 
             //read(sockfd, str, sizeof(str)); 
             if (read(sockfd, str, sizeof(str)) < 0){
             error("ERROR reading from socket");
            } 
             printf("Responds Server :%s\n ", str);
             break;
            //printf("Responds Server : %s\n", str);
/*            printf("From server: %s\n", str); */
/*            printf("Answer back to server: %f\n",float_to_send);*/
/*            send(sockfd, &float_to_send, sizeof(float_to_send),0);*/
            }
            
        if ((strcmp(splitStrings[0],"fmul")) == 0){
            float_to_send = fnum1*fnum2; // Put your value
            bzero(st, sizeof(st)); 
            sprintf(st, "%f", float_to_send);
            //converted_number = htonl(number_to_send);
            printf("From Server: %s\n", str); 
          
            strcat(st,"\n");
            printf("Answer back to server: %s\n",st);
            //write(sockfd, st, sizeof(st));
            if (write(sockfd, st, sizeof(st)) < 0)
            printf("Error writing to server\n");
            bzero(str, sizeof(str)); 
            //read(sockfd, str, sizeof(str)); 
            if (read(sockfd, str, sizeof(str)) < 0){
             error("ERROR reading from socket");
            } 
            printf("Responds Server : %s\n",str);
            break;
/*            printf("From server: %s\n", str); */
/*            printf("Answer back to server: %f\n",float_to_send);*/
/*            send(sockfd, &float_to_send, sizeof(float_to_send),0);*/
            
            }
            //write(sockfd, &float_converted, sizeof(float_converted));}
            
        if ((strcmp(splitStrings[0],"fsub")) == 0){
            float_to_send = fnum1-fnum2; // Put your value
            bzero(st, sizeof(st)); 
            sprintf(st, "%f", float_to_send);
            //converted_number = htonl(number_to_send);
            printf("From Server: %s\n", str); 
          
            strcat(st,"\n");
            printf("Answer back to server: %s\n",st);
            //write(sockfd, st, sizeof(st));
            if (write(sockfd, st, sizeof(st)) < 0)
            printf("Error writing to server\n");
            bzero(str, sizeof(str)); 
             //read(sockfd, str, sizeof(str)); 
             if (read(sockfd, str, sizeof(str)) < 0){
             error("ERROR reading from socket");
            } 
              printf("Responds Server : %s\n", str);
              break;
            //printf("Response from Server : %s\n", str);
/*            printf("From server: %s\n", str); */
/*            printf("Answer back to server: %f\n",float_to_send);*/
/*            send(sockfd, &float_to_send, sizeof(float_to_send),0);*/
            }
        
        
           //printf("Responds Server : ");
            //bzero(str, sizeof(str)); 
            //read(sockfd, str, sizeof(str)); 
            //printf("Responds from Server : %s\n", str);
// Write the number to the opened socket
        //write(sockfd, &converted_number, sizeof(converted_number));
/*	else if ((strncmp(str, "OK\n", 2)) == 0) { */
/*            printf("We are done. Exiting...\n"); */
/*            break; */
/*        } */
        
    
 
 }
 bzero(str, sizeof(str)); 
           // read(sockfd, str, sizeof(str)); 
           // printf("Responds fromn Server : %s\n", str);
}






int main(int argc, char *argv[]) 
{ 
	int sockfd, connfd, port; 
	struct sockaddr_in servaddr, cli; 
	struct hostent *server;

	char delim[]=":";
	char *Desthost=strtok(argv[1],delim);
        char *Destport=strtok(NULL,delim);
        port = atoi(Destport);
  
        //printf("Port: %d\n",(port)); 
       // printf("ip addr: %s\n",Desthost);
	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	//server = gethostbyname(Desthost);
	//bzero((char *) &serv;_addr, sizeof(serv_addr));
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr(Desthost); 
	//servaddr.sin_port = htons(port); 
       // bcopy((char *)server->h_addr, 
        // (char *)&serv;_addr.sin_addr.s_addr,
        // server->h_length);
       // servaddr.sin_addr.s_addr = inet_addr(Desthost); 
	servaddr.sin_port = htons(port); 
	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 
        //printf("Responds Server : ");
	// function for chat 
	func(sockfd); 
        printf("Responds Server : \n");
	// close the socket 
	close(sockfd); 
} 

