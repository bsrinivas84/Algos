// DynamicProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "Common.h"
using namespace std;

int lcslengthNonDP(char *X, char *Y, int m, int n);
int lcslengthDP(char *X, char *Y, int m, int n);
void LCSDP(char* X, int m, char *Y, int n);


//Knapsack Problem
int max(int a, int b) { return (a > b) ? a : b; }

int lis(int arr[], int n);

int getMaxArea(int hist[], int n);

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	// Base Case
	if (n == 0 || W == 0)
		return 0;

	// If weight of the nth item is more than Knapsack capacity W, then
	// this item cannot be included in the optimal solution
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	// Return the maximum of two cases: 
	// (1) nth item included 
	// (2) not included
	else return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
		knapSack(W, wt, val, n - 1)
		);
}

void KnapsackProblem() {
	int val[] = { 60, 10, 120 };
	int wt[] = { 10, 20, 30 };
	int  W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));

}


/* Function to get minimum number of trails needed in worst
case with n eggs and k floors */
int eggDrop(int n, int k)
{
#define INT_MAX 2147483647;
	/* A 2D table where entery eggFloor[i][j] will represent minimum
	number of trials needed for i eggs and j floors. */
	int eggFloor[3][37];
	int res;
	int i, j, x;

	// We need one trial for one floor and 0 trials for 0 floors
	for (i = 1; i <= n; i++)
	{
		eggFloor[i][1] = 1;
		eggFloor[i][0] = 0;
	}

	// We always need j trials for one egg and j floors.
	for (j = 1; j <= k; j++)
		eggFloor[1][j] = j;

	// Fill rest of the entries in table using optimal substructure
	// property
	for (i = 2; i <= n; i++)
	{
		for (j = 2; j <= k; j++)
		{
			eggFloor[i][j] = INT_MAX;
			for (x = 1; x <= j; x++)
			{
				res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
				if (res < eggFloor[i][j])
					eggFloor[i][j] = res;
			}
		}
	}

	// eggFloor[n][k] holds the result
	return eggFloor[n][k];
}

void EggFall()
{
	int n = 2, k = 36;
	printf("\nMinimum number of trials in worst case with %d eggs and "
		"%d floors is %d \n", n, k, eggDrop(n, k));
	//return 0;

}

//1,1,2,3,5,8,13,21,34
int Fibonacci(int n)
{
	int arr[6];
	arr[0] = arr[1] = 1;
	for (int i = 2; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	//printf("%d", arr[4]);

	return(arr[5]);
	//int sum = 

}

int j = 0;
void LIS(int arr, int subarr, int i)
{
	/*
	int k = sizeof(arr);

	if (i > 8)
		return;
	if (arr[i] < arr[i + 1]) {
		subarr[i] = arr[i];


	}
	i++;
	LIS(arr, subarr, i);*/

}

void LongestCommonSubsequence()
{
	//"ABCBDAB"
	char  X[] = "ABC", Y[] = "BDCABA";

	printf("%d %d", sizeof(X), sizeof(Y));
	printf("\n Combinations of all lengths \n");


	for (int i = 0; i < sizeof(X) - 1; i++)
	{


		for (int j = 0; j < sizeof(X) - 1; j++)
		{

			if (i == j)
			{
				//printf("\n");
				continue;
			}
		
			for (int k = 0; k < sizeof(X) - 1; k++)
			{
				if (j == k || i == j || i == k)
				{
					//printf("\n");
					continue;
				}
				printf("%c", X[i]);
				printf("%c", X[j]);
				printf("%c", X[k]);
				printf("\n");
			}
			//printf("\n");
		}
		printf("\n");
	}

}

int LCSLength(char X[], int i,int m, char Y[], int j, int n)
{
	if (i == m || j == n)
	{
		return 0;
	}
	else if (X[i] == Y[j])
	{
	
		return 1 + LCSLength(X, i + 1, m, Y, j + 1, n);
		
	}
	else return max(LCSLength(X, i + 1, m, Y, j, n), LCSLength(X, i, m, Y, j + 1, n));


}

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int count1 = 0;
void lcs(char *X, char *Y, int m, int n)
{
	int L[9][9];

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
			{
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// Following code is used to print LCS
	int index = L[m][n];

	// Create a character array to store the lcs string
	char lcs[10];
	lcs[9] = '\0'; // Set the terminating character

					   // Start from the right-most-bottom-most corner and
					   // one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i - 1] == Y[j - 1])
		{
			lcs[index - 1] = X[i - 1]; // Put current character in result
			i--; j--; index--;     // reduce values of i, j and index
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	// Print the lcs
	cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

int mcs(int A[6], int n)
{
	int M[6] = {0}, maximumsum = 0;

	if (A[0] > 0)
		M[0] = A[0];
	else
		M[0] = 0;

	for (int i = 1; i < n; i++)
	{
		if (M[i - 1] + A[i] > 0)
			M[i] = M[i - 1] + A[i];
		else
			M[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (M[i] > maximumsum)
		{
			maximumsum = M[i];
		}

	}

	return maximumsum;

}
int main()
{
	////KnapsackProblem();
	////EggFall();
	///*int i = 0;
	//printf("%d", Fibonacci(6));*/
	//int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
	//int subarr[9];
	//// LIS(&arr, &subarr,0);

	//LongestCommonSubsequence();

	//char X[] = "ABCBDAB", Y[] = "BDCABA";
	//printf("%d", LCSLength(X, 0, sizeof(X) - 1, Y, 0, sizeof(Y) - 1));

	/*char X[] = "AGGTAB";
	char Y[] = "GXTXAY";
	int m = strlen(X);
	int n = strlen(Y);
	lcs(X, Y, m, n);*/

	//int numbers[] = {1,-3,4,-2,-1,6};//{ -2,11,-4,13,-5,2 };
	//printf("%d", mcs(numbers,sizeof(numbers)/sizeof(int)));

	//char X[] = "AGGTAB";
	//char Y[] = "GXTXAYB";

	//int m = strlen(X);
	//int n = strlen(Y);

	////printf("Length of LCS is %d\n", lcslengthNonDP(X, Y, m, n));
	////printf("Length of LCS is %d\n", lcslengthDP(X, Y, m, n));
	//LCSDP(X,m,Y, n);


//LIS
	//int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//printf("Length of LIS is %d\n", lis(arr, n));


//Maximum Square Sub Matrix

	//bool M[6][5] = { { 0, 1, 1, 0, 1 },
	//{ 1, 1, 0, 1, 0 },
	//{ 0, 1, 1, 1, 0 },
	//{ 1, 1, 1, 1, 0 },
	//{ 1, 1, 1, 1, 1 },
	//{ 0, 0, 0, 0, 0 } };

	//printMaxSubSquare(M);

//Histogram
	int hist[] = { 6, 1, 5, 1, 5, 1, 6 };
	int n = sizeof(hist) / sizeof(hist[0]);
	cout << "Maximum area is " << getMaxArea(hist, n);

	getchar();
	return 0;
}

