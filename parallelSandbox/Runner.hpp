//
//  Runner.hpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#ifndef Runner_hpp
#define Runner_hpp

#include "Common.h"
#include "RunnerDelegate.hpp"

class Runner {
protected:
    int mtag;
private:
    std::thread *t;
public:
    bool active;
    RunnerDelegate *delegate;
    Runner( int tag );
    void thread( );
    bool run( );
    virtual bool runCommand( DelegateCommand *command ) { return false; }
};

#endif /* Runner_hpp */
