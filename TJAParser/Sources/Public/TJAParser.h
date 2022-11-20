#pragma once

#include <iostream>
#include <fstream>
#include "../Public/TJAMap.h"

namespace TJAPARSER {

	void PrintTJA(int flag);

	class TJAParserLib
	{
	
	public:
		TJAParserLib();
		~TJAParserLib();
		TJAMap* ParseTJAFile(string TJAFilePath);
	};

	
}


