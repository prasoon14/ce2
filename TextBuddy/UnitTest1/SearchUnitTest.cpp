#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace executeUserCommand
{		
	TEST_CLASS(ExecuteUserCommand)
	{
	public:
		
		TEST_METHOD(forSearch)
		{
			vector<string> tempStorage = {"Rains of castemere","It's a rainy day","For Starks"};
			string sampleSearchWord = "rain";
			
			string outputString = searchWord(tempStorage, sampleSearchWord);

			string expected = "1. Rains of castemere\n2. It's a rainy day\n";
			Assert::AreEqual(expected, outputString);
		}

	};
}