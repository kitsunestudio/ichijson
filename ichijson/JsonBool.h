//
//  JsonBool.h
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#ifndef __ichijson__JsonBool__
#define __ichijson__JsonBool__

#include <stdio.h>

#include "JsonSerializable.h"

namespace Json {

    class Bool : public Serializable {
    public:
        Bool();
        Bool(bool value);
        ~Bool();

        std::string serialize();
        void deserialize(const std::string string);

        bool value;

    };

}

#endif /* defined(__ichijson__JsonBool__) */
