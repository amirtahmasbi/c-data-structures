// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define length(x) (sizeof(x)/sizeof(x[0]))

// create a global pointer to the head of the linked list
struct node *head = NULL;

// push method
void push(int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->Data = x;
	temp->Next = head;
	head = temp;
	return;
}

// pop method
int pop()
{
	if (head != NULL)
	{
		struct node *temp = head;
		int data = temp->Data;
		head = head->Next;
		free(temp);
		return data;
	}
	else
		return -1;
}

// top method
int top()
{
	if (head != NULL)
		return head->Data;
	else
		return -1;
}

// isempty method
int isempty()
{
	if (head == NULL)
		return 1;
	else
		return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// display the stack status
	printf("Is the stack empty: %d\n", isempty());
	// initialize an array
	int A[] = { 12, 32, 1, 5, 73, 121 };
	for (int i = 0; i < length(A); i++)
	{
		printf("%d ", A[i]);
		push(A[i]);
	}
	printf("is the input data.\n");
	printf("Is the stack empty: %d\n", isempty());
	printf("The last date is: %d\n", pop());
	printf("The last date is: %d\n", top());

	for (int i = 0; i < length(A); i++)
		printf("%d ", pop());

	printf("\nIs the stack empty: %d\n", isempty());

	getchar();
	return 0;
}

