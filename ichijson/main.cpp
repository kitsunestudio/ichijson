//
//  main.cpp
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#include <iostream>
#include "Json.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Json::String hw = "\t\"Hello, World!\" :)\n";
//    std::string hw = "Hello, World! :)\n";
    Json::String deserialized;
    deserialized.deserialize(hw.serialize());
    std::cout << hw.string << std::endl;
    std::cout << hw.serialize() << std::endl;
    std::cout << deserialized.string << std::endl;
    return 0;
}
