#include "../Public/TJAMap.h"

#include <sstream>


void TJAMap::ParseTJAData(list<string> InData)
{
    bool HasParseSongMetaData = false;
    for(int i = 0; i <= InData.size() - 1; i++)
    {
        auto it = InData.begin();
        advance(it, i);

        if(it->length() > 0 && !HasParseSongMetaData)
        {
            if(it->find("COURSE:") != string::npos)
            {
                HasParseSongMetaData = true;
            }
            
            if(it->find("TITLE:") != string::npos && SongTitle.length() == 0)
            {
                TJAPARSER::ParseTJAValue(*it, SongTitle);
                std::cout << "TITLE = " << SongTitle << std::endl;
            }

            if(it->find("SUBTITLE:") != string::npos && Subtitle.length() == 0)
            {
                TJAPARSER::ParseTJAValue(*it, Subtitle);
                std::cout << "SUBTITLE = " << Subtitle << std::endl;
            }

            if(it->find("BPM:") != string::npos)
            {
                TJAPARSER::ParseTJAValue(*it, BaseSongBPM);
                std::cout << "BPM = " << BaseSongBPM << std::endl;
            }

            if(it->find("WAVE:")!= string::npos)
            {
                TJAPARSER::ParseTJAValue(*it, AudioFile);
                std::cout << "AUDIO FILE = " << AudioFile << std::endl;
            }

            if(it->find("OFFSET:")!= string::npos)
            {
                TJAPARSER::ParseTJAValue(*it, SongOffset);
                std::cout << "OFFSET = " << SongOffset << std::endl;
            }

            if(it->find("SONGVOL:")!= string::npos)
            {
                TJAPARSER::ParseTJAValue(*it, SongVolume);
                std::cout << "SONGVOL = " << SongVolume << std::endl;
            }

            if(it->find("SEVOL:")!= string::npos)
            {
                TJAPARSER::ParseTJAValue(*it, SeVolume);
                std::cout << "SEVOL = " << SeVolume << std::endl;
            }

            if(it->find("DEMOSTART:")!= string::npos)
            {
                TJAPARSER::ParseTJAValue(*it, DemoStart);
                std::cout << "DEMOSTART = " << DemoStart << std::endl;
            }

            if(it->find("SCOREMODE:")!= string::npos)
            {
                TJAPARSER::ParseTJAValue(*it, ScoreMode);
                std::cout << "SCOREMODE = " << ScoreMode << std::endl;
            }
        }
        
    }
}
