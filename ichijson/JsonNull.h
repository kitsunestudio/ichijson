//
//  JsonNull.h
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#ifndef __ichijson__JsonNull__
#define __ichijson__JsonNull__

#include <stdio.h>

#include "JsonSerializable.h"

namespace Json {

    class Null : public Serializable {
        Null();
        ~Null();

        std::string serialize();
        void deserialize(std::string);
    };

}

#endif /* defined(__ichijson__JsonNull__) */
