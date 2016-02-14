// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

void BubbleSort(int Input[], int length) {

	int temp = 0;
	for (int i = 0; i < length - 1; i++)
		for (int j = i + 1; j < length; j++)
		{
			if (Input[i] > Input[j])
			{
				temp = Input[i];
				Input[i] = Input[j];
				Input[j] = temp;
			}

		}
	for (int i = 0; i < length; i++)
		printf("%d ", Input[i]);

}

void SelectionSort(int Input[], int length) {

	int temp = 0, index = 0;
	for (int i = 0; i < length - 1; i++)
	{
		temp = Input[i];
		index = i;
		for (int j = i + 1; j < length; j++)
		{
			if (Input[j] < temp) {

				index = j;
			}
		}
		temp = Input[index];
		Input[index] = Input[i];
		Input[i] = temp;

	}

	for (int i = 0; i < length; i++)
		printf("%d ", Input[i]);
}

void InsertionSort(int Input[], int length) {

	int temp = 0, j = 0;
	for (int k = 0; k < length; k++)
		printf("%d ", Input[k]);
	printf("\n");

	for (int i = 1; i <= length - 1; i++)
	{
		temp = Input[i];
		j = i;
		while (Input[j - 1] > temp && j >= 1)
		{
			Input[j] = Input[j - 1];
			j--;
		}
		Input[j] = temp;

		for (int k = 0; k < length; k++)
			printf("%d ", Input[k]);

		printf("\n");
	}

	printf("\n \n \n");

	for (int i = 0; i < length; i++)
		printf("%d ", Input[i]);
}

void ShellSort(int Input[], int length) {

	int temp = 0, j = 0, h = 0;
	for (int k = 0; k < length; k++)
		printf("%d ", Input[k]);
	printf("\n");

	for (h = 1; h < length / 9; h = 3 * h + 1);

	for (; h > 0; h = h / 3)
		for (int i = h + 1; i < length; i++)
		{
			temp = Input[i];
			j = i;
			while (Input[j - h] > temp && j >= h)
			{
				Input[j] = Input[j - h];
				j -= h;
			}
			Input[j] = temp;

			for (int k = 0; k < length; k++)
				printf("%d ", Input[k]);

			printf("\n");
		}

	printf("\n \n \n");

	for (int i = 0; i < length; i++)
		printf("%d ", Input[i]);
}

void Merge(int A[], int Temp[], int left, int mid, int right)
{
	int i, left_end, size, temp_pos;
	left_end = mid - 1;
	temp_pos = left;
	size = right - left + 1;

	while ((left <= left_end) && (mid <= right)) {
		if (A[left] <= A[mid])
		{
			Temp[temp_pos] = A[left];
			temp_pos++;
			left++;
		}
		else {
			Temp[temp_pos] = A[mid];
			temp_pos++;
			mid++;
		}
	}
	while (left <= left_end) {
		Temp[temp_pos] = A[left];
		temp_pos++;
		left++;
	}


	while (mid <= right) {
		Temp[temp_pos] = A[mid];
		temp_pos++;
		mid++;
	}

	for (int i = 0; i <= size; i++) {
		A[right] = Temp[right];
		right = right - 1;
		//printf("%d ", A[k]);
	}


}

void MergeSort(int A[], int temp[], int left, int right)
{
	if (right > left)
	{
		int mid = (left + right) / 2;
		MergeSort(A, temp, left, mid);
		MergeSort(A, temp, mid + 1, right);
		Merge(A, temp, left, mid + 1, right);

		for (int k = 0; k < right - left + 1; k++)
			printf("%d ", A[k]);
		printf("\n");
	}

}

void Swap(int A[], int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int GetPivotItem(int A[], int low, int high) {

	int pivot_item = A[low];
	while (low < high) {

		if (A[low] < pivot_item)
			low++;
		else if (A[high] > pivot_item)
			high--;
		if (low < high)
			Swap(A, low, high);

	}

	A[low] = A[high];
	A[high] = pivot_item;

	return high;

}

int GetPivotItemTemp(int A[], int low, int high) {

	int pivot_item = A[low], left, right;
	left = low;
	right = high;
	while (left < right) {

		if (A[left] < pivot_item)
			left++;
		else if (A[right] > pivot_item)
			right--;
		if (left < right)
			Swap(A, left, right);

	}

	A[low] = A[right];
	A[right] = pivot_item;

	return left;

}
void QuickSort(int A[], int low, int high)
{
	int pivotItem = 0, length = high - low + 1;
	if (high > low)
	{
		pivotItem = GetPivotItem(A, low, high);
		QuickSort(A, low, pivotItem - 1);
		QuickSort(A, pivotItem + 1, high);
	}
	/*for (int k = 0; k < length; k++)
		printf("%d ", A[k]);
	printf("\n");*/
}

struct node
{
	int data;
	struct node *left;
	struct node* right;

};

node* CreateBinaryHeap(int A[], int length)
{
	struct node* head = NULL;
	struct node* temp = NULL;// = (node*)malloc(sizeof(node));

	head = (node*)malloc(sizeof(node));
	head->data = A[0];
	head->left = NULL;
	head->right = NULL;

	temp = head;
	for (int i = 1; i < length; i++) {

		if (head == NULL)
		{
			head = (node*)malloc(sizeof(node));
			head->data = A[i];
			head->left = NULL;
			head->right = NULL;
		}

		else if (head->left == NULL)
		{
			head->left = (node*)malloc(sizeof(node));
			head->data = A[i];
			head->left->left = NULL;
			head->left->right = NULL;
		}
		else if (head->right == NULL)
		{
			head->right = (node*)malloc(sizeof(node));
			head->data = A[i];
			head->right->left = NULL;
			head->right->right = NULL;
		}
		else
		{
			head = head->left;
		}

	}

	//head = temp;

	return temp;
}


node* HeapSort(int A[], int length) {

	 return CreateBinaryHeap(A, length);

	//return head;
}

void PrintElements(struct node* temp) {

	if (temp != NULL && temp-> data)
	{
		printf("\n Data is %d", temp->data);

		PrintElements(temp->left);
		PrintElements(temp->right);
	}

}

int main()
{
	int Input[] = { 20,-1,34,25,0,-2,-10,52,36,10,30 }, Temp[11];
	int length = sizeof(Input) / sizeof(int);
	//BubbleSort(Input, length);
	//SelectionSort(Input, length);
	//InsertionSort(Input, length);
	//ShellSort(Input, length);
	//MergeSort(Input, Temp, 0, 10);
	//QuickSort(Input, 0, 10);
     struct node * temp = HeapSort(Input, length);
	PrintElements(temp);
	//for (int k = 0; k < length; k++)
	//	printf("%d ", Input[k]);
	//printf("\n");

	getchar();
	return 0;
}

