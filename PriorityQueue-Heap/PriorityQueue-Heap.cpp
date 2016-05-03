// PriorityQueue-Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void Init();
void Insert(int element);
int DeleteMin();

int main()
{
	int number_of_elements;
	printf("Enter # of elements");
	scanf_s("%d", &number_of_elements);
	int iter, element;
	Init();
	for (iter = 0; iter < number_of_elements; iter++)
	{
		printf("Enter element {0} \n", iter);
		scanf_s("%d", &element);
		Insert(element);
	}
	for (iter = 0; iter < number_of_elements; iter++)
	{
		printf("%d ", DeleteMin());
	}
	printf("\n");
	getchar();
	return 0;
}

