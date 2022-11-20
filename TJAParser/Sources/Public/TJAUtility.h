#pragma once

#include <sstream>
#include <iostream>
#include <vector>


namespace TJAPARSER
{
    enum TJACourseDifficulty
    {
        Kantan = 0,

        Futsuu = 1,

        Muzukashii = 2,

        Oni = 3,

        InnerOni = 4
    
    };

    template<typename T, typename String>
    void ParseTJAValue(const String & str, T & val) {

        const char delim = ':';
 
        std::vector<std::string> out;
        std::stringstream DataStream(str);
 
        std::string s;
        while (std::getline(DataStream, s, delim)) {
            out.push_back(s);
        }
        DataStream >> out[1];
        std::stringstream DataOut(out[1]);
        DataOut >> val;
    }
    
}

