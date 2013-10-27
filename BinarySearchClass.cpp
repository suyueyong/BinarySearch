///////////////////////////////////////////////////////////////
// BinarySearchClass.cpp      Bianary Search Source File     //
// Yueyong Su                                                //
///////////////////////////////////////////////////////////////
#include <iostream>
#include "BinarySearchClass.h"
using namespace BinarySearchSpace;

//Binary Search Method
int BinarySearchClass::BinarySearch(int arr[], int size, int target)
{
    int high=size-1;
    int low=0;
    int mid;
    while(low<=high)
	{
        mid=low+(high-low)/2;  
        if(arr[mid]==target)
		{
            return mid;
        }
        else if(arr[mid]>target)
		{
            high=mid-1;
        }
        else
		{
            low=mid+1;
        }
        
    }
    return -1;//error
}
/*
int main(int argc, char* argv[])//a simple test main function
{
	std::cout << "\n  " << "Binary Search Test Result: ";
	int arr[5]={2, 4, 6, 8, 9};
	BinarySearchClass bs;
	int index=bs.BinarySearch(arr, 5, 8);
	if(index==3)
		std::cout << "Pass! \n";
	else
		std::cout << "Fail! \n";
}*/

