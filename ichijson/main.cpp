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
    Json::String hw = "\t\"Hello, World!\" :)\n";
    Json::String deserialized;
    deserialized.deserialize(hw.serialize());
    std::cout << hw.value << std::endl;
    std::cout << hw.serialize() << std::endl;
    std::cout << deserialized.value << std::endl;
    Json::Bool boolean;
    boolean.deserialize("   true    ");
    std::cout << boolean.value << std::endl;
    std::cout << boolean.serialize() << std::endl;
    return 0;
}
