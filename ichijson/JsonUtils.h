//
//  JsonUtil.h
//  ichijson
//
//  Created by Brayden Morris on 9/14/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#ifndef ichijson_JsonUtil_h
#define ichijson_JsonUtil_h

#include <functional>

namespace Json {

    static inline std::string &trim_left(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    static inline std::string &trim_right(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }

    static inline std::string &trim(std::string &s) {
        return trim_left(trim_right(s));
    }
}

#endif
