// DataStructuresAlgorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define length(x) (sizeof(x)/sizeof(x[0]))


// decleare front and rear pointers
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
	return;
}

void dequeue()
{
	struct node *temp = front;
	if (front == NULL)
		return;
	if (front == rear)
		front = rear = NULL;
	else
	{
		front = front->next;
	}

	free(temp);
	return;
}

int first()
{
	if (front != NULL)
		return front->data;
	return -1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	// select an input array
	int A[] = { 5, 21, 9, 1, 12, 45, 6 };

	// print the elements of the input array 
	printf("The input array is: { ");
	for (int i = 0; i < length(A); i++)
		printf("%d ", A[i]);

	printf("}\n");


	// test the queue here
	for (int i = 0; i < length(A) / 2; i++)
	{
		printf("Enqueueing %d\n", A[i]);
		enqueue(A[i]);
	}

	printf("Front element %d\n", first());
	printf("Dequeueing 3 times ... \n");
	dequeue();
	dequeue();
	dequeue();
	printf("Front element %d\n", first());
	

	getchar();
	return 0;
}

