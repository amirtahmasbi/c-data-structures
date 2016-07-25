// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define length(x) (sizeof(x)/sizeof(x[0]))

// create a node (the building block of a singly linked list)
struct Node
{
	int Data;
	struct Node *Next;
};


// insert a node at the begining of a linked list
Node* insertFirst(struct Node *head, int data)
{
	// create a node in the heap memory
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->Data = data;

	// set the head node as the next node of temp
	temp->Next = head;

	// insert temp at the first place 
	head = temp;
	return head;
}

// remove the first node of a linked list
Node* removeFirst(struct Node *head)
{
	// save the address to the current head
	struct Node *temp = head;
	// set the address of the new head
	head = head->Next;

	// free the memory
	free(temp);
	return head;
}

// insert a node at the end of a linked list
void insertLast(struct Node* head, int data)
{
	// create a node in the heap memory
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->Data = data;
	temp->Next = NULL;

	// create a current pointer for traversal
	while (head->Next != NULL)
		head = head->Next;

	// insert temp at the end
	head->Next = temp;
	return;
}

// remove the last node of a linked list
void removeLast(struct Node* head)
{
	// create a current pointer for traversal
	while (head->Next->Next != NULL)
		head = head->Next;

	// create a node in the heap memory
	struct Node *temp = head->Next;
	head->Next = NULL;
	free(temp);
	return;
}

// insert data at the xth position of a linked list
void insertAt(struct Node* head, int data, int x)
{
	// create a node in the heap memory
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->Next = NULL;
	temp->Data = data;
	// create a pointer to the linked list positions
	//struct Node *counter = head;
	// find the right position
	for (int i = 0; i < x-1; i++)
	{
		if (head->Next == NULL)
		{
			printf("The last index in the linked list %d is smaller than the target index %d.\n", i, x);
			return;
		}
		else
			head = head->Next;
	}
	if (head->Next != NULL)
		// copy the address of the next node in temp
		temp->Next = head->Next;

	// insert temp after counter 
	head->Next = temp;
	return;
}

// print all elements of a linked list
void printAll(struct Node* head)
{
	printf("Printing linked list element in direct order: \n");
	//struct Node *current = Head;
	while (head != NULL)
	{
		printf("%d ", head->Data);
		head = head->Next;
	}
	printf("\n");
	return;
}


// here it goes the main function
int _tmain(int argc, _TCHAR* argv[])
{
	// create an array of data
	int A[] = {12, 54, 2, 9, 120, 3, 11};

	// create a pointer to the head of the linked list
	struct Node *Head = NULL;

	// initialize the linked list
	Head = insertFirst(Head, A[0]);
	for (int i = 1; i < length(A); i++)
		insertAt(Head, A[i], i);

	// print all elements
	printAll(Head);

	// remove the first element
	Head = removeFirst(Head);

	Head = insertFirst(Head, 800);

	// print all elements
	printAll(Head);

	// insert at the end 
	insertLast(Head, 300);

	// print all elements
	printAll(Head);

	// remove the last element 
	removeLast(Head);

	// print all elements
	printAll(Head);

	getchar();
	return 0;
}
