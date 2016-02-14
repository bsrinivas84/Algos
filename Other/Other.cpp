// Other.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

char A[3];// = {'0','1'};
char B[3];
void Binary(int);
void kstring(int n, int k);

int getval(int(*A)[5], int i, int j, int L, int H) {
	if (i < 0 || i >= L || j < 0 || j >= H)
		return 0;
	else
		return A[i][j];
}

void Binary(int n)
{
	if (n < 1)
		printf("%s\n", A);
	else {
		A[n - 1] = '0';
		Binary(n - 1);
		A[n - 1] = '1';
		Binary(n - 1);
	}
}

void kstring(int n, int k)
{
	if (n < 1)
		printf("%s\n", B);
	else {
		for (int j = 0; j < k; j++) {
			B[n - 1] = j + 48;
			kstring(n - 1, k);

		}
	}
}

void atoi()
{
	char c = NULL;
	while (c != 'z') {
		printf(" \n Enter the value you want to convert \n");
		//scanf_s("%c", &c)
		c = getchar();

		if (c != '\n')
			printf("%d", (c - 48));
	}

}

void itoa()
{
	int c = 0;
	while (c != 9999) {
		printf("Enter the value you want to convert \n");
		scanf_s("%i", &c);

		printf("%c", (c + 48));
	}

}

int main()
{
	/*  Binary(sizeof(A));
	  printf("====================\n");
	   kstring(2,sizeof(B));*/

	//atoi();
	itoa();
	getchar();
	return 0;
}


