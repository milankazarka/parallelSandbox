//
//  main.cpp
//  parallelSandbox
//
//  Created by Milan Kazarka on 3/10/18.
//  Copyright © 2018 Rendering Pixels Limited. All rights reserved.
//

/**
 
    this is an implementation of a simple Companies House crawler.
    Modify this to access speciffic data - currently just the page with basic info on a company is downloaded.
 
    Chain commands together to do further processing.
 
 */

#include "Common.h"
#include "Robot.hpp"
#include "RunnerDownloader.hpp"
#include "FilefeedCommandProvider.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Robot *robot = new Robot();
    if (robot) {
        robot->setCommandProvider(new FilefeedCommandProvider((char*)"BasicCompanyData-2018-03-01-part1_5.csv"));
        for(int n = 0; n < 50; n++) {
            RunnerDownloader *downloader = new RunnerDownloader(n);
            robot->addRunner(downloader);
        }
        while(robot->activeRunners()) sleep(1);
    }
    std::cout << "  done\n";
    return 0;
}
