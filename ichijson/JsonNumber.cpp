//
//  JsonNumber.cpp
//  ichijson
//
//  Created by Brayden Morris on 9/15/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#include "JsonNumber.h"
#include <sstream>
#include "JsonUtils.h"
#include <math.h>

namespace Json {

    long Number::setValue(long value) {
        type = NumberTypeLong;
        longValue = value;
        return value;
    }

    double Number::setValue(double value) {
        type = NumberTypeDouble;
        doubleValue = value;
        return value;
    }

    long Number::getLongValue() {
        switch (type) {
            case NumberTypeLong:
                return longValue;
                break;
            case NumberTypeDouble:
                if (doubleValue >= 0) {
                    return (long)(doubleValue + 0.5);
                } else {
                    return (long)(doubleValue - 0.5);
                }
                break;
            default:
                return 0;
                break;
        }
    }

    double Number::getDoubleValue() {
        switch (type) {
            case NumberTypeLong:
                return (double)longValue;
                break;
            case NumberTypeDouble:
                return doubleValue;
                break;
            default:
                return 0;
                break;
        }
    }

    bool isDigit(char c) {
        std::string digits = "0123456789";
        return digits.find(c) != std::string::npos;
    }

    int valueOf(char c) {
        return (c - 48) % 10;
    }

    void Number::deserialize(const std::string string) {
        std::string newString = string;
        trim(newString);
        std::stringstream is;
        is.str(string); is.clear();
        char c;
        is.get(c);
        bool isNegative = false;
        bool isInteger = true;
        if (c == '-') {
            isNegative = true;
            is.get(c);
        }
        long integerValue = 0;
        while (isDigit(c)) {
            integerValue = integerValue * 10;
            integerValue += valueOf(c);
            if(!is.get(c))
                break;
        }
        double floatValue = integerValue;
        if (c == '.') {
            isInteger = false;
            int exponent = 0;
            is.get(c);
            while (isDigit(c)) {
                --exponent;
                floatValue += valueOf(c) * pow(10.0, exponent);
                if (!is.get(c))
                    break;
            }
        }
        if (c == 'e' or c == 'E') {
            int exponent = 0;
            is.get(c);
            bool exponentIsNegative = false;
            if (c == '-') {
                exponentIsNegative = true;
                is.get(c);
            }
            if (c == '+') {
                is.get(c);
            }
            while (isDigit(c)) {
                exponent = exponent * 10;
                exponent += valueOf(c);
                if(!is.get(c))
                    break;
            }
            if (exponentIsNegative) {
                exponent = exponent * -1;
            }
            if (isInteger) {
                integerValue = integerValue * (long)(pow(10.0, exponent) + 0.5);
            } else {
                floatValue = floatValue * pow(10.0, exponent);
            }
        }
        if (isNegative) {
            if (isInteger) {
                integerValue = integerValue * -1;
            } else {
                floatValue = floatValue * -1;
            }
        }
        if (isInteger) {
            setValue(integerValue);
        } else {
            setValue(floatValue);
        }
    }

    std::string Number::serialize() {
        std::string output = "";
        switch (type) {
            case NumberTypeLong: {
                long working = longValue;
                if (longValue == 0) {
                    output = "0";
                } else if (longValue < 0) {
                    output.append("-");
                    working = -working;
                }
                while (working > 0) {
                    
                }
                break;
            }
            case NumberTypeDouble: {
                break;
            }
            default: {
                output = "0";
                break;
            }
        }
        return output;
    }

}