//
//  Runner.cpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#include "Runner.hpp"

void Runner::thread( ) {
    while(1) {
        std::cout << "runner\n";
        //usleep(100);
        if (delegate) {
            DelegateCommand *command = delegate->runnerDelegateNextCommand(this);
            if (command) {
                runCommand(command);
            } else {
                active = false;
            }
        }
    }
}

void thread_caller(Runner *runner) {
    runner->thread();
}

Runner::Runner( int tag ) {
    delegate = nullptr;
    mtag = tag;
    active = true;
}

bool Runner::run( ) {
    t = new std::thread(thread_caller,this);
    if (t)
        return true;
    return false;
}

