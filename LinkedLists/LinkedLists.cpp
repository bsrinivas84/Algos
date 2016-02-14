// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"

struct node
{
	int value;
	struct node *next;

};


void PrintList(struct node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");

}

struct node* InsertValue(struct node* head)
{
	printf("Enter the value to insert");
	int val = 0;
	scanf_s("%d",&val);

	 //temp = head->next;

	 struct node* temp = (struct node* ) malloc(sizeof(struct node));
	 temp->value = val;
	 temp->next = head->next;
	 head->next = temp;

	 PrintList(head);

	 return head;

}

//head = a, head->next = b, head->next->next = c
//a,b,c
//nodeNext = b
//head->next = a
//head = b
//nodeNext =c
//head->next = b
struct node* ReverseList(struct node* head) {

	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;

	struct node* secondElem = head->next;
	head->next = NULL;
	struct node*  reverseRest=	ReverseList(secondElem);
	secondElem->next = head;
	return reverseRest;

}

struct node* ReverseInPairs(struct node* head)
{
	if (head == NULL|| head->next == NULL)
		return head;

	struct node* temp = head;
	struct node* temp1 = temp->next->next;
	head = head->next;
	head->next = temp;
	head->next->next = temp1;
	head->next->next = ReverseInPairs(head->next->next);

	return head;
}

int main()
{
	/*int a[] = { 1,2,3,4,5 };
	int length = sizeof(a) / sizeof(a[0]);
	printf("Length is %d \n ", length);
	for (int i = 0; i < length; i++)
		printf("%d %d \n", i, a[i]);*/

	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->value = 10;
	head->next = second;

	second->value = 20;
	second->next = third;

	third->value = 30;
	

	struct node* fourth = (node *)malloc((sizeof(node)));
	third->next = fourth;
	fourth->value = 40;
	

	struct node* fifth = (node *)malloc((sizeof(node)));
	fourth->next = fifth;
	fifth->value = 50;

	struct node* sixth = (node *)malloc((sizeof(node)));
	fifth->next = sixth;
	sixth->value = 60;

	sixth->next = NULL;

	PrintList(head);


	//head = InsertValue(head);

	//PrintList(ReverseList(head));

	PrintList(ReverseInPairs(head));

	getchar();
	getchar();

	return 0;

}

