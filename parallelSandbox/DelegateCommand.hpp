//
//  DelegateCommand.hpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#ifndef DelegateCommand_hpp
#define DelegateCommand_hpp

#include <stdio.h>

class DelegateCommand {
public:
    char rawdata[4096];
    DelegateCommand( );
    void addData( char *data );
};

#endif /* DelegateCommand_hpp */
