//
//  JsonNumber.h
//  ichijson
//
//  Created by Brayden Morris on 9/15/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#ifndef __ichijson__JsonNumber__
#define __ichijson__JsonNumber__

#include <stdio.h>
#include "JsonSerializable.h"

namespace Json {
    typedef enum NumberType{
        NumberTypeLong,
        NumberTypeDouble,
    } NumberType ;

    class Number : public Serializable {
    public:
        long setValue(long value);
        double setValue(double value);
        long getLongValue();
        double getDoubleValue();
        virtual void deserialize(const std::string string);
        virtual std::string serialize();
    private:
        long longValue;
        double doubleValue;
        NumberType type;

    };
}

#endif /* defined(__ichijson__JsonNumber__) */
