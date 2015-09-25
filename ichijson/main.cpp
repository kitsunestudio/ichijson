//
//  main.cpp
//  ichijson
//
//  Created by Brayden Morris on 9/13/15.
//  Copyright (c) 2015 Brayden Morris. All rights reserved.
//

#include <iostream>
#include "Json.h"

bool runTest(std::string action, bool test, bool verbose) {
    std::string testAction = action;
    std::cout << (test ? (verbose ? testAction.append(" successful.\n") : "") : testAction.append(" failed.\n"));
    return test;
};

void runTests(bool verbose) {

    // .::STRING::.
    Json::String string;

    string.deserialize("\"\"");
    runTest("Deserialize empty string", string.value.compare("") == 0, verbose);

    string.value = "";
    runTest("Serialize empty string", string.serialize().compare("\"\"") == 0, verbose);

    string.deserialize("\"Hello\"");
    runTest("Deserialize string", string.value.compare("Hello") == 0, verbose);

    string.deserialize(" \"Hello\" ");
    runTest("Deserialize string with whitespace", string.value.compare("Hello") == 0, verbose);

    string.value = "Hello";
    runTest("Serialize string", string.serialize().compare("\"Hello\"") == 0, verbose);

    string.deserialize("\"\\\"\"");
    runTest("Deserialize string with quotation mark", string.value.compare("\"") == 0, verbose);

    string.value = "\"";
    runTest("Serialize string with quotation mark", string.serialize().compare("\"\\\"\"") == 0, verbose);

    string.deserialize("\"\\\\\"");
    runTest("Deserialize string with reverse solidus", string.value.compare("\\") == 0, verbose);

    string.value = "\\";
    runTest("Serialize string with reverse solidus", string.serialize().compare("\"\\\\\"") == 0, verbose);

    string.deserialize("\"\\/\"");
    runTest("Deserialize string with solidus", string.value.compare("/") == 0, verbose);

    string.value = "/";
    runTest("Serialize string with solidus", string.serialize().compare("\"\\/\"") == 0, verbose);

    runTest("Deserialize string with escaped unicode", false, verbose);

    runTest("Serialize string with unicode", false, verbose);


    // .::NUMBER::.
    Json::Number number;

    number.deserialize("0");
    runTest("Deserialize zero as integer", number.getLongValue() == 0, verbose);

    number.deserialize("42");
    runTest("Deserialize number as integer", number.getLongValue() == 42, verbose);

    number.deserialize("-42");
    runTest("Deserialize negative number as integer", number.getLongValue() == -42, verbose);

    number.setValue((long)0);
    runTest("Read integer zero as float", number.getDoubleValue() == 0.0, verbose);

    number.setValue((long)42);
    runTest("Read integer as float", number.getDoubleValue() == 42.0, verbose);

    number.setValue((long)-42);
    runTest("Read negative integer as float", number.getDoubleValue() == -42.0, verbose);

    number.deserialize("0.0");
    runTest("Deserialize zero as float", number.getDoubleValue() == 0.0, verbose);

    number.deserialize("42.42");
    runTest("Deserialize number as float", number.getDoubleValue() == 42.42, verbose);

    number.deserialize("-42.42");
    runTest("Deserialize negative number as float", number.getDoubleValue() == -42.42, verbose);

    number.setValue(0.0);
    runTest("Read float zero as integer", number.getLongValue() == 0, verbose);

    number.setValue(42.42);
    runTest("Read float as integer", number.getLongValue() == 42, verbose);

    number.setValue(-42.42);
    runTest("Read negative float as integer", number.getLongValue() == -42, verbose);

    number.setValue((long)0);
    runTest("Serialize long zero", number.serialize().compare("0") == 0, verbose);

    // .::BOOLEAN::.
    Json::Bool boolean;


    // .::NULL::.
    Json::Null null;

    null.deserialize("null");
    runTest("Deserialize null", true, verbose);

    null.deserialize(" null ");
    runTest("Deserialize null with whitespace", true, verbose);

    runTest("Serialize null", null.serialize().compare("null") == 0, verbose);


    // .::OBJECT::.


    // .::ARRAY::.
    
}

int main(int argc, const char * argv[]) {
    runTests(false);
    return 0;
}
