//
//  DelegateCommand.cpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#include "DelegateCommand.hpp"
#include <string.h>

DelegateCommand::DelegateCommand( ) {
    rawdata[0] = 0x00;
}

void DelegateCommand::addData( char *data ) {
    if (data) {
        if (strlen(data)<4095)
            strcpy((char*)rawdata, data);
        else {
            strncpy((char*)rawdata, data, 4095);
            rawdata[4095] = 0x00;
        }
    }
}
