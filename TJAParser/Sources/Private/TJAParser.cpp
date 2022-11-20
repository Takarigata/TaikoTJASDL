#include "../Public/TJAParser.h"

#include <fstream>
#include <iostream>
#include <codecvt>

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
		std::wifstream wif(TJAFilePath);
		wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
		wstringstream wss;
		wss << wif.rdbuf();
		
		std::wcout << "encoded UTF 8" << wss.str() << endl;
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
			//OutTJAMap->ParseTJAData(TJAData);
		}
	
		return OutTJAMap;
	}
	

}