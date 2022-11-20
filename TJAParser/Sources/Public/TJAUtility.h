#pragma once

#include <sstream>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>
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

    inline std::string TaikoDifficultyToString(TJACourseDifficulty InDiff)
    {
        switch (InDiff)
        {
            case Futsuu:
                return "Futsuu";
            
            case Kantan:
                return "Kantan";
            
            case Muzukashii:
                return "Muzukashii";
            
            case Oni:
                return "Oni";

            case InnerOni:
                return "Inner-Oni";

            default:
                return "EnumError";
        }
    }

    inline TJACourseDifficulty StringToDifficulty(std::string InDiffString)
    {
        std::map<std::string, TJACourseDifficulty> DiffMap;
        std::string ParsedDiff;
        ParseTJAValue(InDiffString, ParsedDiff);
        DiffMap.insert({ "Oni", Oni});
        DiffMap.insert({ "Hard", Muzukashii});
        DiffMap.insert({ "Normal", Futsuu});
        DiffMap.insert({ "Easy", Kantan});
        TJACourseDifficulty out = DiffMap.find(ParsedDiff)->second;
        return out;
    }
    
}

