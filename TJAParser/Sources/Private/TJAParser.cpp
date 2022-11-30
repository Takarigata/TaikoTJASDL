#include "../Public/TJAParser.h"

#include <fstream>
#include <iostream>
#include <codecvt>

#include<stdio.h>
#include<windows.h>
#include <cstdio>
#include <windows.h>


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
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
		TJAMap* OutTJAMap = new TJAMap();
		SetConsoleOutputCP( 65001 );
	
		std::wifstream wif(TJAFilePath);
		wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
		wstringstream wss;
		wss << wif.rdbuf();
	
		fstream TJAFileStream;
		list<string> TJAData;
		TJAFileStream.open(TJAFilePath, ios::in);
		if(TJAFileStream.is_open())
		{
			string CurrentLine;
			while(getline(TJAFileStream, CurrentLine))
			{
				TJAData.push_back(CurrentLine);
			}
		}
	
		return OutTJAMap;
	}
	

}