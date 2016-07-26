// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define length(x) (sizeof(x)/sizeof(x[0]))

// create global front and rear pointers and set them to NULL
struct node *front = NULL;
struct node *rear = NULL;

// enqueue method
void enqueue(int x)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->next = NULL;

	if (rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
	return;
}

// dequeue method
int dequeue()
{
	// check whether the queue is empty
	if (front == NULL)
	{
		rear = NULL;
		return -1;
	}

	struct node *temp = front;
	int data = temp->data;

	if (front == rear)
		front = rear = NULL;
	else
		front = front->next;

	free(temp);
	return data;
}

// first method
int first()
{
	if (front != NULL)
		return front->data;
	else
		return -1;
}

// isempty method
int isempty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}

// size method
int size()
{
	struct node *temp = front;
	int count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

// main method
int _tmain(int argc, _TCHAR* argv[])
{
	int A[] = { 54, 62, 31, 9, 2, 91 };
	printf("Is the queue empty: %d\n", isempty());

	for (int i = 0; i < length(A); i++)
		enqueue(A[i]);

	printf("Size of queue is: %d\n", size());
	printf("First element of queue is: %d\n", first());
	dequeue();
	dequeue();
	printf("First element of queue is: %d\n", dequeue());
	printf("Size of queue is: %d\n", size());
	dequeue();
	dequeue();
	dequeue();
	printf("First element of queue is: %d\n", dequeue());

	getchar();
	return 0;
}

