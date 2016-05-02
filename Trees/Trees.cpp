// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"


struct node
{
	int data;
	node* left;
	node* right;

};
struct LinkedList {
	node* address;
	LinkedList* next;
};


LinkedList* head1 = NULL;// (LinkedList*)malloc(sizeof(LinkedList));
LinkedList* temp1 = head1;

LinkedList* NonRecursivehead1;// = (LinkedList*)malloc(sizeof(LinkedList));

LinkedList* NonRecursivetemp1;// = NonRecursivehead1;

void push(node *address)
{
	if (head1 == NULL)
	{
		head1 = (LinkedList*)malloc(sizeof(LinkedList));
		temp1 = head1;
	}
	else //if (head1->next == NULL)
	{
		head1->next = (LinkedList*)malloc(sizeof(LinkedList));
		head1 = head1->next;
	}

	head1->address = address;
	head1->next = NULL;
	//counter++;
	//stack[counter] = address;
}

node* Pop()
{
	LinkedList* temp = temp1;

	if (!temp1)
		return NULL;

	while (temp->next != NULL)
		temp = temp->next;

		//node* address = temp1->address;
		//temp1 = temp1->next;
		return(temp->address);
	
	/*else
		return NULL;*/
}

node* Peek()
{
	if (temp1 != NULL && temp1->address)
		return temp1->address;
	else
		return NULL;
}

node* CreateTree()
{
	int input[] = { 1,2,3,4,5,6,7 };
	node* head = (node*)malloc(sizeof(node));
	head->data = input[0];
	head->left = NULL;
	head->right = NULL;
	node* temp = head;
	int data;
	int length = sizeof(input) / sizeof(input[0]);
	head1->address = NULL;
	head1->next = NULL;

	for (int i = 0; i < length - 2; i = i + 2)
	{
		if (head == NULL)
		{
			node* head = (node*)malloc(sizeof(node));
			head->data = input[i];
		}

		if (head->left == NULL)
		{
			head->left = (node*)malloc(sizeof(node));
			head->left->left = NULL;
			head->left->right = NULL;
			head->left->data = input[i + 1];
		}
		if (head->right == NULL)
		{
			head->right = (node*)malloc(sizeof(node));
			head->right->left = NULL;
			head->right->right = NULL;
			head->right->data = input[i + 2];
		}

		if (Peek())
			head = Pop();
		else
		{
			push(head->right);
			head = head->left;
		}
	}

	return temp;
}

void PreOder(node* head)
{
	if (head != NULL)
		printf("%d", head->data);
	if (head->left != NULL)
		PreOder(head->left);
	if (head->right != NULL)
		PreOder(head->right);
}

void InOder(node* head)
{
	if (head->left != NULL)
		InOder(head->left);
	if (head != NULL)
		printf("%d", head->data);

	if (head->right != NULL)
		InOder(head->right);
}

void PostOder(node* head)
{

	if (head->left != NULL)
		PostOder(head->left);
	if (head->right != NULL)
		PostOder(head->right);
	if (head != NULL)
		printf("%d", head->data);
}

void pushNonRecursive(node *address)
{
	if (NonRecursivehead1 == NULL)
	{
		NonRecursivehead1 = (LinkedList*)malloc(sizeof(LinkedList));
		NonRecursivehead1->next = NULL;
		NonRecursivehead1->address = address;
		NonRecursivetemp1 = NonRecursivehead1;
	}
	else
	{
		NonRecursivehead1 = NonRecursivetemp1;

		while (NonRecursivehead1->next != NULL)
			NonRecursivehead1 = NonRecursivehead1->next;

		/*node* temp= (node*)malloc(sizeof(node));
		temp = address;*/
		NonRecursivehead1->next = (LinkedList*)malloc(sizeof(LinkedList));
		NonRecursivehead1->next->address = address;
		NonRecursivehead1->next->next = NULL;
	}
}

node* PopNonRecursive()
{
	if (NonRecursivetemp1 != NULL)
	{
		NonRecursivehead1 = NonRecursivetemp1;
		LinkedList* Prev = (LinkedList*)malloc(sizeof(LinkedList));
		int flag = 0;
		while (NonRecursivehead1->next != NULL)
		{
			flag = 1;
			Prev = NonRecursivehead1;
			NonRecursivehead1 = NonRecursivehead1->next;
		}

		node* address = NonRecursivehead1->address;
		if (flag == 1)
		{
			NonRecursivehead1 = Prev;
			NonRecursivehead1->next = NULL;
		}
		else
		{
			NonRecursivehead1->next = NULL;
			NonRecursivehead1->address = NULL;
			NonRecursivehead1 = NULL;
		}
		//NonRecursivetemp1 = NonRecursivetemp1->next;

		return(address);
	}
	else
		return NULL;
}

node* PeekNonRecursive()
{
	if (NonRecursivetemp1 != NULL && NonRecursivetemp1->address)
		return NonRecursivetemp1->address;
	else
		return NULL;
}

void NonRecursivePreOrder(node* root)
{
	NonRecursivehead1 = NonRecursivetemp1 = NULL;
	while (root)
	{
		printf("%d", root->data);
		if (root->left && root->right)
		{
			pushNonRecursive(root->right);
			root = root->left;
		}
		else if (root->left)
			root = root->left;
		else
			root = PopNonRecursive();
	}
}

void NonRecursiveInOrder(node* root)
{
	NonRecursivehead1 = NonRecursivetemp1 = NULL;
	while (1)
	{
		while (root)
		{
			pushNonRecursive(root);
			root = root->left;
		}

		root = PopNonRecursive();
		if (root == NULL)
			break;
		printf("%d", root->data);
		root = root->right;
	}
}

//void NonRecursivePostOrder(node* root)
//{
//	NonRecursivehead1 = NonRecursivetemp1 = NULL;
//	node* prev = NULL;
//	while (1)
//	{
//		while (root)
//		{
//			pushNonRecursive(root);
//			prev = root;
//			root = root->left;
//		}
//
//		root = PopNonRecursive();
//
//		if (root == NULL)
//			break;
//		printf("%d", root->data);
//
//		root = PopNonRecursive();
//
//		if (root == prev)
//		{
//			pushNonRecursive(root);
//				pushNonRecursive(root->right);
//		}
//
//		if(root != NULL)
//			root = root->right;
//
//		/*if(root != NULL)
//		pushNonRecursive(root);*/
//		
//			
//	}
//}

// 1  
//4 5
//void NonRecursivePostOrder(node* root)
//{
//	node* prev = NULL;
//	int flag = 0;
//	while (root)
//	{
//		
//		if ((root->left || root->right)&& flag==0)
//		{
//			push(root);
//			if (root->left != NULL && flag ==0)
//			{
//				prev = root;
//				root = root->left;
//			}
//			else if (root->right != NULL && flag ==0)
//			{
//				push(root->right);
//			}
//
//		}
//		else if ( root->right && flag == 1)
//		{
//			if (root->right != NULL && flag == 1)
//			{
//				if(root->right->left != NULL || root->right->right != NULL)
//				push(root);
//				prev = root;
//				root = root->right;
//				flag = 0;
//			}
//		}
//		else
//		{
//			printf("%d", root->data);
// 			root = Pop();
//			if (root == prev && flag == 1)
//			{
//				printf("%d", root->data);
//				root = Pop();
//			}
//			flag = 1;
//		}
//	}
//}

void NonRecursivePostOrder(node* root)
{
	node* prev = NULL, *current = NULL;
	if (!root) return;
	push(root);

	while (current) {
		current = Pop();

		if (!prev || prev->left == current || prev->right == current) {
			if (current->left)
			{
				push(current->left);
				prev = current;
				current = current->left;
			}
			else if (current->right)
			{
				push(current->right);
				prev = current;
				current = current->right;
			}
			else if (current->left == prev) {
				if (current->right)
					push(current->right);

				prev = current;
			}
			else {
				printf("%d", current->data);
				prev = current;
				//current = Pop();
			}


		}
	}
}

node* CreateTreeNonRecursive()
{
	int input[] = { 1,2,3,4,5,6,7 };
	node* head = (node*)malloc(sizeof(node));
	head->data = input[0];
	head->left = NULL;
	head->right = NULL;
	node* temp = head;
	int data;
	int length = sizeof(input) / sizeof(input[0]);
	/*if (head1 == NULL)
		head1 = (LinkedList *)malloc(sizeof(LinkedList));
	head1->address = NULL;
	head1->next = NULL;*/

	for (int i = 0; i < length - 2; i = i + 2)
	{
		if (head == NULL)
		{
			node* head = (node*)malloc(sizeof(node));
			head->data = input[i];
		}

		if (head->left == NULL)
		{
			head->left = (node*)malloc(sizeof(node));
			head->left->left = NULL;
			head->left->right = NULL;
			head->left->data = input[i + 1];
		}
		if (head->right == NULL)
		{
			head->right = (node*)malloc(sizeof(node));
			head->right->left = NULL;
			head->right->right = NULL;
			head->right->data = input[i + 2];
		}

		if (PeekNonRecursive())
			head = PopNonRecursive();
		else
		{
			pushNonRecursive(head->right);
			head = head->left;
		}
	}

	return temp;
}

int main()
{
	//struct node* head = CreateTree();
	/*PreOder(head);
	printf("\n\n");
	InOder(head);
	printf("\n\n");
	PostOder(head);*/
	struct node* head = CreateTreeNonRecursive();
	NonRecursivePreOrder(head);
	printf("\n");
	NonRecursiveInOrder(head);
	printf("\n");
	NonRecursivePostOrder(head);
	getchar();
	return 0;
}

