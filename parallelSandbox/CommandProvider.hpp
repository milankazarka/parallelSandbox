//
//  CommandProvider.hpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#ifndef CommandProvider_hpp
#define CommandProvider_hpp

#include "Common.h"
#include "DelegateCommand.hpp"
#include "Runner.hpp"

class CommandProvider {
public:
    CommandProvider( );
    virtual DelegateCommand *nextCommand( Runner *runner ) { return nullptr; };
};

#endif /* CommandProvider_hpp */
