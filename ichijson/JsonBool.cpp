//
//  JsonBool.cpp
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#include "JsonBool.h"

namespace Json {

    Bool::Bool() {
        value = false;
    }

    Bool::Bool(bool value) {
        this->value = value;
    }

    Bool::~Bool() {
    }

    std::string Bool::serialize() {
        std::string retVal;
        if (value) {
            retVal = "true";
        } else  {
            retVal = "false";
        }
        return retVal;
    }

    void Bool::deserialize(const std::string string) {
        std::string newString = string;
        if (trim(newString).substr(0, 5).compare("true") == 0) {
            value = true;
        } else {
            value = false;
        }
    }

}