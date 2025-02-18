#include "pch.h"
#include "CppUnitTest.h"
#include "..\тестовое1\func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(add(1, 2) == 3);
		}
		TEST_METHOD(TestMethod2) 
		{
			Assert::IsTrue(add(-1, 1) == 0);
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::IsTrue(add(-1, -1) == -2);
		}
		TEST_METHOD(TestMethod4)
		{
			Assert::IsTrue(add(0, 0) == 0);
		}
		TEST_METHOD(TestMethod5)
		{
			Assert::IsTrue(add(5, 9) == 14);
		}
		TEST_METHOD(TestMethod6)
		{
			Assert::IsTrue(add(5, 10) == 15);
		}
	};
}
