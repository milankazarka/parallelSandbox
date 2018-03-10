//
//  Robot.cpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#include "Robot.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Robot::thread( ) {
    while(1) {
        std::cout << "thread\n";
        usleep(100000);
    }
}

void thread_caller(Robot *robot) {
    robot->thread();
}

Robot::Robot( ) {
    mprovider = nullptr;
    t = new std::thread(thread_caller,this);
}

void Robot::setCommandProvider( CommandProvider *provider ) {
    mprovider = provider;
}

void Robot::addRunner( Runner *runner ) {
    runner->delegate = this;
    mrunners.push_back(runner);
    runner->run();
}

DelegateCommand *Robot::runnerDelegateNextCommand( Runner *runner ) {
    if (!runner)
        return nullptr;
    m.lock();
    std::cout << "  Robot::runnerDelegateNextCommand\n";
    DelegateCommand *command = nullptr;
    if (mprovider) {
        command = mprovider->nextCommand(runner);
    }
    m.unlock();
    return command;
}

/**  we are active if even one runner is active
 */
bool Robot::activeRunners( ) {
    for (int i=0; i<mrunners.size(); i++) {
        if (mrunners[i]->active)
            return true;
    }
    return false;
}
