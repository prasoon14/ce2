#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(sortTest)
		{
			vector<string> tempStorage = { "apple", "mango", "carrot", "banana" };
			sortFile(tempStorage);
			Assert::IsTrue(areFileSorted());
		}

	};
}