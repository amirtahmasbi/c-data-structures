// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define length(x) (sizeof(x)/sizeof(x[0]))

// create a global pointer to the head of the linked list
struct Node *head = NULL;


// insert a node at the begining of a linked list
void insertFirst(int data)
{
	// create a node in the heap memory
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->Data = data;

	// set the head node as the next node of temp
	temp->Next = head;

	// insert temp at the first place 
	head = temp;
	return;
}

// remove the first node of a linked list
void removeFirst()
{
	// save the address to the current head
	struct Node *temp = head;
	// set the address of the new head
	head = head->Next;

	// free the memory
	free(temp);
	return;
}

// insert a node at the end of a linked list
void insertLast(int data)
{
	// create a node in the heap memory
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->Data = data;
	temp->Next = NULL;

	// create a current pointer for traversal
	struct Node *current = head;
	while (current->Next != NULL)
		current = current->Next;

	// insert temp at the end
	current->Next = temp;
	return;
}

// remove the last node of a linked list
void removeLast()
{
	// create a current pointer for traversal
	struct Node *current = head;
	while (current->Next->Next != NULL)
		current = current->Next;

	// define a pointer to the last element
	struct Node *temp = current->Next;
	current->Next = NULL;
	free(temp);
	return;
}

// insert data at the xth position of a linked list
void insertAt(int x, int data)
{
	// create a node in the heap memory and initialize it
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->Next = NULL;
	temp->Data = data;

	// set the first element
	if (x == 0)
	{
		temp->Next = head;
		head = temp;
		return;
	}

	// create a current pointer for traversal
	struct Node *current = head;
	// find the right position
	for (int i = 0; i < x-1; i++)
			current = current->Next;

	// copy the address of the next node in temp
	temp->Next = current->Next;

	// insert temp after counter 
	current->Next = temp;
}


// reverse the linked list
void reverse()
{
	struct Node *current = head;
	struct Node *prev = NULL;
	struct Node *next = NULL;

	while (current != NULL)
	{
		next = current->Next;
		current->Next = prev;
		prev = current;
		current = next;

	}
	head = prev;
	return;
}

// print all elements of a linked list
void printAll()
{
	printf("Printing linked list element in direct order: \n");
	struct Node *current = head;
	while (current != NULL)
	{
		printf("%d ", current->Data);
		current = current->Next;
	}
	printf("\n");
	return;
}

// print all elements of a linked list
void print(struct Node *p)
{
	if (p == NULL)
	{
		printf("\n");
		return;
	}
	printf("%d ", p->Data);
	print(p->Next);
}

// print all elements of a linked list
void reversePrint(struct Node *p)
{
	if (p == NULL)
		return;
	reversePrint(p->Next);
	printf("%d ", p->Data);
}


// here it goes the main function
int _tmain(int argc, _TCHAR* argv[])
{
	// create an array of data
	int A[] = {12, 54, 2, 9, 120, 3, 11};

	// initialize the linked list
	for (int i = 0; i < length(A); i++)
		insertAt(i, A[i]);

	// print all elements
	printAll();

	// remove the first element
	removeFirst();

	// print all elements
	printAll();

	// insert at the end 
	insertLast(300);

	// print all elements
	printAll();

	// remove the last element 
	removeLast();

	insertFirst(80);

	// print all elements
	print(head);
	reversePrint(head);

	reverse();

	// print all elements
	printAll();

	getchar();
	return 0;
}
