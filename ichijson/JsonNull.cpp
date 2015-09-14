//
//  JsonNull.cpp
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#include "JsonNull.h"

namespace Json {

    Null::Null() {
    }

    Null::~Null() {
    }

    std::string Null::serialize() {
        std::string retVal = "null";
        return retVal;
    }

    void Null::deserialize(const std::string string) {
    }

}