#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testUserCommand
{		
	TEST_CLASS(testUserCommand)
	{
	public:
		
		TEST_METHOD(forSort)
		{
			vector<string> tempStorage = { "apple", "mango", "carrot", "banana" };
			sortFile(tempStorage);
			Assert::IsTrue(isFileSorted(tempStorage));
		}

	};
}