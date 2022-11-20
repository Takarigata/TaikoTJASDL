﻿#pragma once
#include <list>
#include <string>
#include "../Public/TJAUtility.h"

using namespace std;

class TJACourse
{
    public:

        TJACourse() = default;
        ~TJACourse() = default;
    
        TJAPARSER::TJACourseDifficulty Difficulty;

        int CourseLevel;
        
        int CourseBaloonLevel;

        int CourseScoreInit;

        int CourseScoreDiff;

        list<string> CourseData;
};
