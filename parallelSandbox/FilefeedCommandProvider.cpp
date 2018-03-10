//
//  FilefeedCommandProvider.cpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#include "FilefeedCommandProvider.hpp"

FilefeedCommandProvider::FilefeedCommandProvider( char *filename )
: CommandProvider()
{
    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    read = getline(&line, &len, fp); // header
}

DelegateCommand *FilefeedCommandProvider::nextCommand( Runner *runner ) {
    if (fp) {
        if ((read = getline(&line, &len, fp)) != -1) {
            DelegateCommand *command = new DelegateCommand();
            command->addData(line);
            return command; // delete when finished
        }
    }
    return nullptr;
}
