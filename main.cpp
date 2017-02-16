//
//  main.cpp
//  client-Chat
//
//  Created by Travis Haycock on 2017-02-09.
//  Copyright © 2017 Travis Haycock. All rights reserved.
//



/*---8----------------8-----------8---------------8--------------------8-----------------------8--
 
 CLIENT SIDE OF THE CHAT PROGRAM- COMMAND LINE NO UI
 
 
 
 
 ----8--------------8---------------8--------------8---------------------8---------------------8-*/

#include <iostream>
#include <cstdlib>
#include <string>




extern "C"{
#include "StartConnection.h"
}




int main(int argc, const char * argv[]) {

   
    setup();
    
    return 0;
}
