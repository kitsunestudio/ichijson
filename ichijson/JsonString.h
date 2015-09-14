//
//  JsonString.h
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#ifndef __ichijson__JsonString__
#define __ichijson__JsonString__

#include <stdio.h>
#include <string>

#include "JsonSerializable.h"

namespace Json {

    class String : public Serializable {
    public:
        String();
        String(const String &string);
        String(std::string string);
        String(const char *chars);
        ~String();

        virtual std::string serialize();
        virtual void deserialize(std::string string);

        std::string string;
    };

}

#endif /* defined(__ichijson__JsonString__) */
