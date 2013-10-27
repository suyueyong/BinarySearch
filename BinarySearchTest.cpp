///////////////////////////////////////////////////////////////
// BinarySearchTest.cpp      Bianary Search Test File        //
// Yueyong Su                                                //
///////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <time.h>
#include "UnitTestBase.h"
#include "BinarySearchClass.h"
using namespace Test;
using namespace BinarySearchSpace;

//TestEven class to test array with even length
//Using the random array to increase the test coverage 
class TestEven: public TestBase<TestEven>
{
public:
	TestEven() //constructor
	{ 
		srand((unsigned)time(0));
		//random array 
		for(int i=0; i<arr_size; i++)	
		{	
			arr[i]=rand()%100;
		}
		//sort the array	
		std::sort(arr, arr+arr_size);
		//adding i to every element to make sure there is no repeat elements
		for(int i=0; i<arr_size; i++)
		{
			arr[i]+=i;
		}
		std::cout << "\n\n  Testing Array With Even Length";
	}
    //test the first element
	bool testFirst()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[0]) == 0, "testFirst");
	}
	//test the last element
	bool testLast()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[arr_size-1]) == (arr_size-1), "testLast");
	}
	//test the middle element
	bool testMid()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[(arr_size-1)/2]) == ((arr_size-1)/2), "testMid");
	}
	//test random element
	bool testRand()
	{
		int r=rand()%arr_size;
		return checkResult(bs.BinarySearch(arr, arr_size, arr[r]) == r, "testRand");
	}
	//execute all the tests in this class
	bool test()
	{
		bool t1;
		t1 = doTest(&TestEven::testFirst);
		bool t2;
		t2 = doTest(&TestEven::testLast);
		bool t3;
		t3 = doTest(&TestEven::testMid);
		bool t4;
		t4 = doTest(&TestEven::testRand);

		return t1&&t2&&t3&&t4;
	}

private:
	static const int arr_size=10;//array size
	int arr[arr_size];
	BinarySearchClass bs;
};

//TestOdd class to test array with odd length
//Using the random array to increase the test coverage 
class TestOdd: public TestBase<TestOdd>
{
public:
	TestOdd() //constructor
	{ 
		srand((unsigned)time(0));
		//random array 
		for(int i=0; i<arr_size; i++)
		{		
			arr[i]=rand()%100;
		}
		//sort the array	
		std::sort(arr, arr+arr_size);
		//adding i to every element to make sure there is no repeat elements
		for(int i=0; i<arr_size; i++)
		{		
			arr[i]+=i;
		}
		std::cout << "\n\n  Testing Array With Odd Length";
	}
	//test the first element
	bool testFirst()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[0]) == 0, "testFirst");
	}
	//test the last element
	bool testLast()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[arr_size-1]) == (arr_size-1), "testLast");
	}
	//test the middle element
	bool testMid()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[(arr_size-1)/2]) == ((arr_size-1)/2), "testMid");
	}
	//test random element
	bool testRand()
	{
		int r=rand()%arr_size;
		return checkResult(bs.BinarySearch(arr, arr_size, arr[r]) == r, "testRand");
	}
	//execute all the tests in this class
	bool test()
	{
		bool t1;
		t1 = doTest(&TestOdd::testFirst);
		bool t2;
		t2 = doTest(&TestOdd::testLast);
		bool t3;
		t3 = doTest(&TestOdd::testMid);
		bool t4;
		t4 = doTest(&TestOdd::testRand);

		return t1&&t2&&t3&&t4;
	}

private:
	static const int arr_size=11;//array size
	int arr[arr_size];
	BinarySearchClass bs;
};

//TestLarge class to test large array
//Using the random array to increase the test coverage 
class TestLarge: public TestBase<TestLarge>
{
public:
	TestLarge() //constructor
	{ 
		srand((unsigned)time(0));
		//random array 
		for(int i=0; i<arr_size; i++)
		{		
			arr[i]=rand()%10000;
		}
		//sort the array	
		std::sort(arr, arr+arr_size);
		//adding i to every element to make sure there is no repeat elements
		for(int i=0; i<arr_size; i++)
		{		
			arr[i]+=i;
		}
		std::cout << "\n\n  Testing Large Array";
	}
	//test the first element
	bool testFirst()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[0]) == 0, "testFirst");
	}
	//test the last element
	bool testLast()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[arr_size-1]) == (arr_size-1), "testLast");
	}
	//test the middle element
	bool testMid()
	{
		return checkResult(bs.BinarySearch(arr, arr_size, arr[(arr_size-1)/2]) == ((arr_size-1)/2), "testMid");
	}
	//test random element
	bool testRand()
	{
		int r=rand()%arr_size;
		return checkResult(bs.BinarySearch(arr, arr_size, arr[r]) == r, "testRand");
	}
	//execute all the tests in this class
	bool test()
	{
		bool t1;
		t1 = doTest(&TestLarge::testFirst);
		bool t2;
		t2 = doTest(&TestLarge::testLast);
		bool t3;
		t3 = doTest(&TestLarge::testMid);
		bool t4;
		t4 = doTest(&TestLarge::testRand);

		return t1&&t2&&t3&&t4;
	}

private:
	static const int arr_size=1000;//array size
	int arr[arr_size];
	BinarySearchClass bs;
};

//TestSpecial class to test special cases
//Using special array in every test cases
class TestSpecial: public TestBase<TestSpecial>
{
public:
	TestSpecial() //constructor
	{ 
		std::cout << "\n\n  Testing Special Cases";
	}
	//test the array with repeating elements, the unique target existing in the array
	bool testRepeat()
	{
		int arr[15]={3, 3, 3, 4, 4, 4, 8, 9, 9, 9, 20, 20, 25, 30, 30};
		return checkResult(bs.BinarySearch(arr, 15, 8) == 6, "testRepeat");
	}
	//test the array with repeating elements, the unique target not existing in the array
	bool testRepeat2()
	{
		int arr[5]={5, 5, 5, 5, 5};
		return checkResult(bs.BinarySearch(arr, 5, 13) == -1, "testReapeat2");
	}
	//test the array with negative elements
	bool testNegative()
	{
		int arr[8]={-11, -9, -8, -5, 0, 5, 9, 12};
		return checkResult(bs.BinarySearch(arr, 8, -5) == 3, "testNegative");
	}
	//test the case that target does not exist in the array
	bool testNoExisting()
	{
		int arr[9]={1, 2, 3, 4, 5, 6, 7, 8, 9};
		return checkResult(bs.BinarySearch(arr, 9, 13) == -1, "testNoExisting");
	}
	//test a simple case that the index is equal to the value
	bool testSimple()
	{
		int arr[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		return checkResult(bs.BinarySearch(arr, 10, 4) == 4, "testSimple");
	}
	//test array with only one element
	bool testOne()
	{
		int arr[1]={5};
		return checkResult(bs.BinarySearch(arr, 1, 5) == 0, "testOne");
	}
	//test array with two element
	bool testTwo()
	{
		int arr[2]={17, 61};
		return checkResult(bs.BinarySearch(arr, 2, 61) == 1, "testTwo");
	}
	//test array with three element
	bool testThree()
	{
		int arr[3]={8, 13, 26};
		return checkResult(bs.BinarySearch(arr, 3, 13) == 1, "testThree");
	}
	//execute all the tests in this class
	bool test()
	{
		bool t1;
		t1 = doTest(&TestSpecial::testRepeat);
		bool t2;
		t2 = doTest(&TestSpecial::testRepeat2);
		bool t3;
		t3 = doTest(&TestSpecial::testNoExisting);
		bool t4;
		t4 = doTest(&TestSpecial::testSimple);
		bool t5;
		t5 = doTest(&TestSpecial::testOne);
		bool t6;
		t6 = doTest(&TestSpecial::testTwo);
		bool t7;
		t7 = doTest(&TestSpecial::testThree);
		bool t8;
		t8 = doTest(&TestSpecial::testNegative);
	
		return t1&&t2&&t3&&t4&&t5&&t6&&t7&&t8;
	}

private:
	BinarySearchClass bs;
};

//function to check all the tests
bool alltest()
{
	bool t1;
	TestEven te;
	t1 = te.test();
	bool t2;
	TestOdd to;
	t2 = to.test();
	bool t3;
	TestLarge tl;
	t3 = tl.test();
	bool t4;
	TestSpecial ts;
	t4 = ts.test();

	return t1&&t2&&t3&&t4;
}

int main(int argc, char* argv[])
{
	Title("Testing BinarySearch");//test title

	if(alltest())
		std::cout << "\n\n  All tests passed\n\n";
	else
		std::cout << "\n\n  At least one test failed\n\n";	
}
