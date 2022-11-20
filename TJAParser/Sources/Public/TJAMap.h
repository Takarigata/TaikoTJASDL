#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Public/TJACourse.h"

using namespace std;

class TJAMap
{
    
    public:

        TJAMap() = default;
        ~TJAMap() = default;
    
        //TJA DATA
        string SongTitle;

        string Subtitle;

        string AudioFile;

        int BaseSongBPM;

        float SongOffset;

        int SongVolume;

        int SeVolume;

        float DemoStart;

        int ScoreMode;

        vector<TJACourse> TJACourses;
        //----------------------------

        //Parsing Function
        void ParseTJAData(list<string> InData);
    
};

