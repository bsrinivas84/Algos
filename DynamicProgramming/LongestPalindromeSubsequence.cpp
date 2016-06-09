//Returns the length of the longest palindromic subsequence in seq
#include "stdafx.h"
#include<stdio.h>
#include<string.h>

// A utility function to get max of two integers
int maxlps(int x, int y) { return (x > y) ? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
	int n = strlen(str);
	int i, j, cl;
	int L[16][16];  // Create a table to store results of subproblems


	// Strings of length 1 are palindrome of lentgh 1
	for (i = 0; i < n; i++)
		L[i][i] = 1;

	// Build the table. Note that the lower diagonal values of table are
	// useless and not filled in the process. The values are filled in a
	// manner similar to Matrix Chain Multiplication DP solution (See
	// http://www.geeksforgeeks.org/archives/15553). cl is length of
	// substring
	for (cl = 2; cl <= n; cl++)
	{
		for (i = 0; i<n - cl + 1; i++)
		{
			j = i + cl - 1;
			if (str[i] == str[j] && cl == 2)
				L[i][j] = 2;
			else if (str[i] == str[j])
				L[i][j] = L[i + 1][j - 1] + 2;
			else
				L[i][j] = maxlps(L[i][j - 1], L[i + 1][j]);
		}
	}

	return L[0][n - 1];
}



// A utility function to print a substring str[low..high]
void printSubStrspace(char* str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		printf("%c", str[i]);
}


// This function prints the longest palindrome substring(LPS)
// of str[]. It also returns the length of the longest palindrome
int longestPalSubstrspace(char *str)
{
	int maxLength = 1;  // The result (length of LPS)

	int start = 0;
	int len = strlen(str);

	int low, high;

	// One by one consider every character as center point of 
	// even and length palindromes
	for (int i = 1; i < len; ++i)
	{
		// Find the longest even length palindrome with center points
		// as i-1 and i.  
		low = i - 1;
		high = i;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 > maxLength)
			{
				start = low;
				maxLength = high - low + 1;
			}
			--low;
			++high;
		}

		// Find the longest odd length palindrome with center 
		// point as i
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && str[low] == str[high])
		{
			if (high - low + 1 > maxLength)
			{
				start = low;
				maxLength = high - low + 1;
			}
			--low;
			++high;
		}
	}

	printf("Longest palindrome substring is: ");
	printSubStrspace(str, start, start + maxLength - 1);

	return maxLength;
}