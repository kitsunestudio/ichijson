//
//  JsonSerializable.h
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#ifndef __ichijson__JsonSerializable__
#define __ichijson__JsonSerializable__

#include <stdio.h>
#include <string>

namespace Json {

    class Serializable {
    public:
        virtual std::string serialize() = 0;
        virtual void deserialize(const std::string string) = 0;
    };



}



#endif /* defined(__ichijson__JsonSerializable__) */
