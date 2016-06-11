#include "stdafx.h"

int StairWays(int n, int m)
{
	int res[11];
	res[0] = 1; res[1] = 1;
	for (int i = 2; i < n; i++)
	{
		res[i] = 0;
		for (int j = 1; j <= i && j <= m; j++)
		{
			res[i] += res[i-j];
		}

	}

	return res[n - 1];

}