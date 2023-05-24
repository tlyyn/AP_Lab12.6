#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.6_2/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL;
			Elem* last = NULL;
			int value = 1;

			enqueue(first, last, value);

			Assert::IsNotNull(first);
			Assert::IsNotNull(last);
			Assert::AreEqual(value, first->info);
			Assert::AreEqual(value, last->info);
		}
	};
}
