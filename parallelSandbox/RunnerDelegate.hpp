//
//  RunnerDelegate.hpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#ifndef RunnerDelegate_hpp
#define RunnerDelegate_hpp

#include "DelegateCommand.hpp"

class Runner;

class RunnerDelegate {
public:
    virtual DelegateCommand *runnerDelegateNextCommand( Runner *runner ) { return nullptr; };
};

#endif /* RunnerDelegate_hpp */
