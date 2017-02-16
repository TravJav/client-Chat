//
//  StartConnection.h
//  client-Chat
//
//  Created by Travis Haycock on 2017-02-09.
//  Copyright © 2017 Travis Haycock. All rights reserved.
//

#ifndef StartConnection_h
#define StartConnection_h

#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>




    
    
    
    char error_message(); // used for displaying errors
    void setup(); // first method ran in application
//char accept_message();
char rec_file();
char re_file();
#endif /* StartConnection_h */
