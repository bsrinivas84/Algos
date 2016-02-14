// Searching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

void RotatedArrayFindElement(int input[], int Start, int End, int length)
{
	int data = 5; int mid = 0;
	
		mid = Start + End- Start / 2;

		if (input[mid] == data)
		{
			printf("Elemendt found at %d", mid);
		}
		if (input[mid] < data)
			RotatedArrayFindElement(input, mid, End, length / 2);

		else if(input[mid] > data)
			RotatedArrayFindElement(input, Start, mid-1, length / 2);

		/*Start++;
		End--;*/
}

int main()
{
	//TwoelementsSumCLosestToZero();
	int input[] = {15,16,19,20,25,1,3,4,5,7,10,14};

	RotatedArrayFindElement(input, 0, sizeof(input) / sizeof(int) - 1, sizeof(input) / sizeof(int));

	getchar();
    return 0;
}

