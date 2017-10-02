#include "stdafx.h"
#include "CppUnitTest.h"
#include "../sudoku_pair/Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT_generate3
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		int result[10010][81];
		int number = 10000;
		TEST_METHOD(TestMethod1)
		{
			Core core;			
			int mode = 1;
			core.generate(number, mode, result);
			for (int i = 0; i < number; i++)
			{
				int blankNum = 0;
				for (int j = 0; j < SUDOKU_SIZE; j++)
				{
					if (result[i][j] == 0)
					{
						blankNum++;
					}
				}
				bool left = 20 <= blankNum;
				bool right = blankNum <= 31;
				Assert::IsTrue(left && right);
			}
		}
		TEST_METHOD(TestMethod2)
		{
			Core core;
			int mode = 2;			
			core.generate(number, mode, result);
			for (int i = 0; i < number; i++)
			{
				int blankNum = 0;
				for (int j = 0; j < SUDOKU_SIZE; j++)
				{
					if (result[i][j] == 0)
					{
						blankNum++;
					}
				}
				bool left = 32 <= blankNum;
				bool right = blankNum <= 43;
				Assert::IsTrue(left && right);
			}
		}
		TEST_METHOD(TestMethod3)
		{
			Core core;
			int mode = 3;
			core.generate(number, mode, result);
			for (int i = 0; i < number; i++)
			{
				int blankNum = 0;
				for (int j = 0; j < SUDOKU_SIZE; j++)
				{
					if (result[i][j] == 0)
					{
						blankNum++;
					}
				}
				bool left = 44 <= blankNum;
				bool right = blankNum <= 55;
				Assert::IsTrue(left && right);
			}
		}
		TEST_METHOD(TestMethod4)
		{
			int puzzle[81] = {
				1, 2, 3, 4, 5, 6, 7, 8, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 9,
				0, 0, 0, 0, 0, 0, 0, 0, 8,
				0, 0, 0, 0, 0, 0, 0, 0, 7,
				0, 0, 0, 0, 0, 0, 0, 0, 6,
				0, 0, 0, 0, 0, 0, 0, 0, 5,
				0, 0, 0, 0, 0, 0, 0, 0, 4,
				0, 0, 0, 0, 0, 0, 0, 0, 3,
				0, 0, 0, 0, 0, 0, 0, 0, 2
			};
			int solution[81] = { 0 };
			Core c;
			Assert::IsFalse(c.solve(puzzle, solution));
		}
	};
}