#include "stdafx.h"

int minJ(int x, int y)
{
	return x > y ? y : x;
}

int minJumps(int arr[], int n)
{
	int Jumps[6];

	Jumps[0] = 0;
	for (int i = 1; i < n; i++)
	{
		Jumps[i] = _CRT_INT_MAX;
		for (int j = 0; j < i; j++)
		{
			if (i <= j + arr[j] && Jumps[j] != _CRT_INT_MAX)
			{
				Jumps[i] = minJ(Jumps[i], Jumps[j] + 1);
				break;
			}
		}
	}

	return Jumps[n - 1];
}