//
//  StartConnection.c
//  client-Chat
//
//  Created by Travis Haycock on 2017-02-09.
//  Copyright © 2017 Travis Haycock. All rights reserved.
//

#include "StartConnection.h"
 #include <fcntl.h>
#include <pthread.h>
#define LENGTH (512)
#define FILENAME "/Users/travishaycock/Desktop/testMe.txt"
#include <errno.h>
#include <sys/stat.h>
#define PORT_NUMBER (20022) // port number where to port in application

int clientSocket;
char buffer[LENGTH];
struct sockaddr_in serverAddr;
socklen_t addr_size;



void setup(){
    
 /*---- Create the socket. The three arguments are: ----*/
    /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    
    /*---- Configure settings of the server address struct ----*/
    /* Address family = Internet */
    serverAddr.sin_family = AF_INET;
    
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(PORT_NUMBER);
    
    /* Set IP address to localhost */
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    /* Set all bits of the padding field to 0 */
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    
    /*---- Connect the socket to the server using the address struct ----*/
    addr_size = sizeof serverAddr;
    connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
    
    /*---- Read the message from the server into the buffer ----*/
   
    
    
   // recv(clientSocket, buffer, 1024, 0);
 
    
    /*---- Print the received message ----*/
    //printf("Data received: %s",buffer);
    
    
   rec_file();
    close(clientSocket);
}



char rec_file(){
    
    char send_str [LENGTH]; /* message to be sent to server*/
    int f; /* file handle for receiving file*/
    ssize_t sent_bytes, rcvd_bytes, rcvd_file_size;
    int recv_count; /* count of recv() calls*/
    char recv_str[LENGTH]; /* buffer to hold received data */
    size_t send_strlen; /* length of transmitted string */
    sprintf(send_str, "%s\n", FILENAME); /* add CR/LF (new line) */
    
    send_strlen = strlen(send_str); /* length of message to be transmitted */
    if( (sent_bytes = send(clientSocket, FILENAME, send_strlen, 0)) < 0 ) {
        perror("send error");
        return -1;
    }
    /* attempt to create file to save received data. 0644 = rw-r--r-- */
    
    /* attempt to create file to save received data. 0644 = rw-r--r-- */
    if ( (f = open(FILENAME, O_WRONLY|O_CREAT, 0644)) < 0 )
    {
        perror("error creating file");
        return -1;
    }
    


    recv_count = 0; /* number of recv() calls required to receive the file */
    rcvd_file_size = 0; /* size of received file */
    /* continue receiving until ? (data or close) */
    while ( (rcvd_bytes = recv(clientSocket, recv_str,LENGTH, 0)) > 0 )
    {
        recv_count++;
        rcvd_file_size += rcvd_bytes;
        
        if (write(f, recv_str, rcvd_bytes) < 0 )
        {
            perror("error writing to file");
            return -1;
        }
    }
    close(f); /* close file*/
    printf("Client Received: %d bytes in %d recv(s)\n", rcvd_file_size,recv_count);
    return rcvd_file_size;
}
    
    
    
    
    
    
    
    
    
    
    
    




