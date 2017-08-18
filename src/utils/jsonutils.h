#ifndef JSONUTILS_H
#define JSONUTILS_H

#include "jsoncpp/json/json.h"

#include <iostream>

class JsonUtils
{
public:
    static Json::Value stringToJson(std::string str, bool *ok = 0);
};

#endif // JSONUTILS_H
