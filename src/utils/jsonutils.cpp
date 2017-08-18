#include "jsonutils.h"

Json::Value JsonUtils::stringToJson(std::string str, bool *ok)
{
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(str.c_str(), root);

    if(!parsingSuccessful)
    {
        std::cout  << "Failed to parse" << reader.getFormattedErrorMessages();

        if(ok) *ok = false;
    }

    if(ok) *ok = true;

    return root;
}
