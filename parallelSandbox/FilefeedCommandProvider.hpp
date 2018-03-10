//
//  FilefeedCommandProvider.hpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

/**
 
    we feed runners with line data from for example a CSV file
    - this only makes sense if each runner than has a time consuming task associated with the line data
 */

#ifndef FilefeedCommandProvider_hpp
#define FilefeedCommandProvider_hpp

#include "CommandProvider.hpp"

class FilefeedCommandProvider : public CommandProvider {
private:
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
public:
    FilefeedCommandProvider( char *filename );
    DelegateCommand *nextCommand( Runner *runner );
};

#endif /* FilefeedCommandProvider_hpp */
