//
//  Robot.hpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#ifndef Robot_hpp
#define Robot_hpp

#include "Runner.hpp"
#include <vector>
#include <thread>
#include "RunnerDelegate.hpp"
#include "CommandProvider.hpp"

class Robot : public RunnerDelegate {
private:
    std::vector<Runner*> mrunners;
    std::thread *t;
    std::mutex m;
    CommandProvider *mprovider;
public:
    Robot( );
    void thread( );
    void addRunner( Runner *runner );
    void setCommandProvider( CommandProvider *provider );
    DelegateCommand *runnerDelegateNextCommand( Runner *runner );
    bool activeRunners( );
};

#endif /* Robot_hpp */
