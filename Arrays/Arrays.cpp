// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//using namespace std;
void mergeSortedArrays() {

	int ar1[] = { 1, 5, 9, 10, 15, 20 };
	int ar2[] = { 2, 3, 8, 13 };

	//printf("%d", sizeof(ar1)/ sizeof(ar1[0]));
	int ar1size = sizeof(ar1) / sizeof(ar1[0]);
	int ar2size = sizeof(ar2) / sizeof(ar2[0]);

	/*for(int i = 0; i < ar1size;i++)
		for (int j = 0; j < ar2size; j++)
		{
			if (ar1[i] > ar2[j])
			{
				int temp = ar1[i];
				ar1[i] = ar2[j];
				ar2[j] = temp;

			}
		}*/

	for (int i = ar1size; i >0 ; i--)
		for (int j = ar2size; j > 0; j--)
		{
			if (ar2[j] > ar1[i])
			{
				int temp = ar1[i];
				ar1[i] = ar2[j];
				ar2[j] = temp;
			}

		}



}

void merge(int ar1[], int ar2[], int m, int n)
{
	// Iterate through all elements of ar2[] starting from
	// the last element
	for (int i = n - 1; i >= 0; i--)
	{
		/* Find the smallest element greater than ar2[i]. Move all
		elements one position ahead till the smallest greater
		element is not found */
		int j, last = ar1[m - 1];
		for (j = m - 1; j >= 0 && ar1[j] > ar2[i]; j--)
			ar1[j + 1] = ar1[j];

		// If there was a greater element
		if (j != m - 1)
		{
			ar1[j + 1] = ar2[i];
			ar2[i] = last;
		}
	}
}


int main()
{

	int ar1[] = { 1, 5, 9, 10, 15, 20 };
	int ar2[] = { 2, 3, 8, 13 };

	//printf("%d", sizeof(ar1)/ sizeof(ar1[0]));
	int ar1size = sizeof(ar1) / sizeof(ar1[0]);
	int ar2size = sizeof(ar2) / sizeof(ar2[0]);
	//mergeSortedArrays();
	merge(ar1,ar2,ar1size,ar2size);

	printf("After Merging \nFirst Array: ");
	for (int i = 0; i < ar1size; i++)
		printf("%d ", ar1[i]);
		printf("\nSecond Array: ");
	for (int i = 0; i<ar2size; i++)
		printf("%d ", ar2[i]);


	getchar();
    return 0;
}

