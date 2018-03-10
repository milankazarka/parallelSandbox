//
//  RunnerDownloader.cpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#include "RunnerDownloader.hpp"

RunnerDownloader::RunnerDownloader( int tag )
: Runner(tag) {
}

bool RunnerDownloader::runCommand( DelegateCommand *command ) {
    if (!command)
        return false;
    
    // multi-threading messes up std::cout
    
    printf("  RunnerDownloader::runCommand tag(%d)\n",mtag);
    //std::cout << "      process line(" << command->rawdata << ")\n";
    
    char* token = strtok((char*)command->rawdata, ",");
    for(int n = 0; n < 32; n++)
        token = strtok(NULL, ",");
    if (token) {
        char command[4096];
        command[0] = 0x00;
        strcat((char*)command,"/usr/local/bin/wget -t1 ");
        strcat((char*)command,token);
        printf("    pull(%s)\n",(char*)command);
        system((char*)command);
    }
    
    delete command;
    return true;
}
