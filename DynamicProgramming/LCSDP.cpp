#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int maxLCSDP(int i, int j)
{
	return i > j? i : j;
}

void LCSDP(char* X,int m, char *Y, int n)
{
	int LCS[7][8];
	char LCSString[8];
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				LCS[i][j] = 0;

			else if (X[i-1] == Y[j-1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;

			else
				LCS[i][j] = maxLCSDP(LCS[i - 1][j], LCS[i][j - 1]);

		}

	}


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", LCS[i][n]);

		printf("\n");
	}

	int i = m;
	int j = n;
	int count = LCS[m][n];
	LCSString[count] = '\0';
	while (i > 0 && j > 0)
	{
		if (X[i-1] == Y[j-1])
			LCSString[count-1] = X[i-1], i--, j--, count--;

		else if (LCS[i - 1][j] > LCS[i][j - 1])
			i--;
		else
			j--;

	}
	cout << LCSString;
	//printf("%s", LCSString);
}