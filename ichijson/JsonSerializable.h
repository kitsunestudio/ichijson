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
#include <functional>

namespace Json {

    class Serializable {
    public:
        virtual std::string serialize() = 0;
        virtual void deserialize(std::string string) = 0;
    };

    // trim from start
    static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    // trim from end
    static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }

    // trim from both ends
    static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
    }

}



#endif /* defined(__ichijson__JsonSerializable__) */
