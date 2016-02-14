// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "math.h"

int sum = 0;
int Recursive(int n)
{
	if (n == 0)
		//return 1;
		sum = 0;
	else
	{
		printf("************Print before recursion. Sum is %d and n is %d \n", sum, n);
		sum = Recursive(n - 1)+n;
		printf("Print after recursion. Sum is %d and n is %d \n", sum, n);
	}
	return sum;

}

int f[5] = {0,0,0,0,0};
int DynamicFibonacciTopDown(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (f[n] != 0) return f[n];

	return f[n] = DynamicFibonacciTopDown(n - 1) + DynamicFibonacciTopDown(n - 2); //f[n - 2] + f[n - 1];

}

int fb[5] = { 0,0,0,0,0 };
int DynamicFibonacciBottomUp(int n)
{
	f[0] = f[1] = 1;

	for (int i = 2; i < n; i++)
		f[i] = f[i - 1] + f[i - 2];

	return(f[n-1]);

}

int simpleFibonacci(int n)
{
	int a = 0, b = 1, sum = 0, i = 0;

	for (int i = 0; i < n-1; i++)
	{
		sum = a + b;
		a = b;
		b = sum;

	}

	return sum;
}


int factorial(int n)
{
	int fact[10] = { 1 };

	for (int i = 1; i < n; i++) {
		fact[i] = i * fact[i-1];
	}

	return fact[n-1];
}

int factorialRecursive(int n)
{
	int fact[10] = { 1 };
	if (n == 0 || n == 1)
		return 1;
	return n*factorialRecursive(n-1);
}

int factorialRecursiveDynamic(int n)
{
	int fact[12] = { 1 };
	/*if (n == 0 || n == 1)
		return 1;
	*/

	fact[0] = fact[1] = 1;

	/*if (fact[n - 1] != 0) 
		return fact[n-1];
*/
	/*if (n > 0)
		return n*factorialRecursiveDynamic(n-1);*/

	int prev = 1;
	for (int i = 2; i < n; i++)
	{
		//fact[i] = i* fact[i - 1];
		prev = i *prev;
	}

	return prev*n; // fact[n - 1] * n;

	//return n*factorialRecursiveDynamic(n - 1);

}


char substringList[1024][1024];
void combinations(char X[], int length)
{

	for (int i = 0; i < length - 1; i++)
	{
	//	printf("i=%d", i);

		if (X[i] != '\0')
			printf("%c", X[i]);
		for (int j = 0; j < length - 1; j++)
		{
			if (X[j] != '\0')
				printf("%c", X[j]);

			if (i == j)
			{
				continue;
			}
			//printf(",j=%d", j);
			for (int k = 0; k < length - 1; k++)
			{
				if (j == k || i == j || i == k)
				{
					printf("\n");
					continue;
				}
			//	printf(",k=%d \n", k);

				if (X[k] != '\0')
					printf("%c", X[k]);
				printf("\n");
			}
			//printf("\n");
		}
		printf("\n");
	}

	if (length-1 > 0)
	{
		printf("************************\n");
		char substr[3];
		memcpy(substr, X, length-1);
		substr[length - 2] = '\0';
		combinations(substr, length - 1);
	}

}

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i)); //backtrack
		}
	}
}

int max = 0;
int max1 = 0;
int max2 = 0;
int greatestnumber = 0;
int MaxInArray(int a[], int length)
{
	
	if (length == 0)
		return -1;
	if (length == 1)
		return a[0];

	/*if (length > 1) {
		max = a[0] > MaxInArray(&a[1], length - 1) ? a[0] : MaxInArray(&a[1], length - 1);
		return max;
	}*/

	//if (length > 1) {
	//	max = MaxInArray(&a[1], length - 1);
	//	return (max > a[0] ? max : a[0]);
	//}

	if (length > 1)
	{
	/*	max1 = MaxInArray(&a[0], length / 2);
		greatestnumber = greatestnumber > max1 ? greatestnumber : max1;
		max2 = MaxInArray(&a[length/2], length -length/2);
		greatestnumber = greatestnumber > max2 ? greatestnumber : max2;
		return (greatestnumber);*/

		return	fmax(MaxInArray(&a[0], length / 2), MaxInArray(&a[length / 2], length - (length / 2)));

	// No No
	/*	return MaxInArray(&a[0], length / 2) > MaxInArray(&a[length / 2], length - length / 2)
			? MaxInArray(&a[0], length / 2) : MaxInArray(&a[length / 2], length - length / 2);*/
	}



}



int main()
{
	//Recursive(5);
	//printf("%d", DynamicFibonacciTopDown(10));
	//printf("%d", DynamicFibonacciBottomUp(10));
	//printf("%d", simpleFibonacci(10));
	//printf("%d", factorial(10));
	/*printf("%d \n", factorialRecursive(12));
	printf("%d \n", factorialRecursiveDynamic(12));*/
	/*char combstring[] = "ABC";
	combinations("ABC", sizeof("ABC"));*/

	//char str[] = "ABC";
	//int n = strlen(str);
	//permute(str, 0, n - 1);

	
	int a[] = { 154,48,159,43,49,155,157, 160 };
	printf("Max in array is %d",MaxInArray(a,8));

	getchar();
	return 0;
}

