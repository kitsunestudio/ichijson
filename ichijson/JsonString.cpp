//
//  JsonString.cpp
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#include "JsonString.h"

#include <sstream>

namespace Json {

    String::String() {
        value = "";
    }
    String::String(const String &string) {
        value = string.value;
    }
    String::String(std::string string) {
        value = string;
    }
    String::String(const char *chars) {
        value = chars;
    }
    String::~String() {
    }

    std::string String::serialize() {
        std::stringstream is, os;
        is.str(value);
        is.clear();
        os.str("");
        os.clear();
        os << "\"";
        char c;
        while (is.get(c)) {
            switch (c) {
                case '\"':
                    os << "\\\"";
                    break;
                case '\\':
                    os << "\\\\";
                    break;
                case '/':
                    os << "\\/";
                    break;
                case '\b':
                    os << "\\b";
                    break;
                case '\f':
                    os << "\\f";
                    break;
                case '\n':
                    os << "\\n";
                    break;
                case '\r':
                    os << "\\r";
                    break;
                case '\t':
                    os << "\\t";
                    break;
                //
                default:
                    os << c;
                    break;
            }
        }
        os << "\"";
        return os.str();
    }

    void String::deserialize(const std::string string) {
        std::string newString = string;
        std::stringstream is, os;
        is.str(Json::ltrim(newString));
        is.clear();
        os.str("");
        os.clear();
        char c;
        is.get(c);
        if (c == '\"') {
            while (is.get(c)) {
                if (c == '\\') {
                    if (is.get(c)){
                        switch (c) {
                            case '\"':
                                os << '\"';
                                break;
                            case '\\':
                                os << '\\';
                                break;
                            case '/':
                                os << '/';
                                break;
                            case 'b':
                                os << '\b';
                                break;
                            case 'f':
                                os << '\f';
                                break;
                            case 'n':
                                os << '\n';
                                break;
                            case 'r':
                                os << '\r';
                                break;
                            case 't':
                                os << '\t';
                                break;
                            default:
                                os << '\\' << c;
                                break;
                        }
                    }
                } else if (c == '\"'){
                    break;
                } else {
                    os << c;
                }
            }
        }
        value = os.str();
    }

}