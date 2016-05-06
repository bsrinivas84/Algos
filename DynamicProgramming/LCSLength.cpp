/* A Naive recursive implementation of LCS problem */
#include"stdafx.h"

int maxlength(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcslengthNonDP(char *X, char *Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcslengthNonDP(X, Y, m - 1, n - 1);
	else
		return maxlength(lcslengthNonDP(X, Y, m, n - 1), lcslengthNonDP(X, Y, m - 1, n));
}

/* Utility function to get max of 2 integers */
int maxlength(int a, int b)
{
	return (a > b) ? a : b;
}
