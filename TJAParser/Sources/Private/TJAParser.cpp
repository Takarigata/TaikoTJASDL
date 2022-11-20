#include "../Public/TJAParser.h"

namespace TJAPARSER {


void PrintTJA(int flag)
{
	std::cout << "WESH" << flag << std::endl;
}
	
	TJAParserLib::TJAParserLib()
	{}

	TJAParserLib::~TJAParserLib()
	{}

	TJAMap* TJAParserLib::ParseTJAFile(string TJAFilePath)
	{
		TJAMap* OutTJAMap = new TJAMap();
		fstream TJAFileStream;
		list<string> TJAData;
		TJAFileStream.open(TJAFilePath, ios::in);
		if(TJAFileStream.is_open())
		{
			string CurrentLine;
			while(getline(TJAFileStream, CurrentLine))
			{
				//cout << CurrentLine << endl;
				TJAData.push_back(CurrentLine);
			}
			OutTJAMap->ParseTJAData(TJAData);
		}
	
		return OutTJAMap;
	}



}