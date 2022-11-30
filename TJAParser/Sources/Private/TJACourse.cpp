#include "../Public/TJACourse.h"

void TJACourse::CreateRandomData(int diff)
{
    Difficulty = static_cast<TJAPARSER::TJACourseDifficulty>(diff);
    
    CourseLevel = rand();

    CourseBaloonLevel = rand();

    CourseScoreInit = rand();

    CourseScoreDiff = rand();

    int randData = rand() % 150 + 0;
    for(int i = 0; i < randData; i++)
    {
        string ExampleData = "Data";
        ExampleData.append(std::to_string(rand()));
        CourseData.push_back(ExampleData);
    }
}