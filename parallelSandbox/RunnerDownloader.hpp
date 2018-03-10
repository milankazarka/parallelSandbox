//
//  RunnerDownloader.hpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

#ifndef RunnerDownloader_hpp
#define RunnerDownloader_hpp

#include "Runner.hpp"

class RunnerDownloader : public Runner {
public:
    RunnerDownloader( int tag );
    bool runCommand( DelegateCommand *command );
};

#endif /* RunnerDownloader_hpp */
