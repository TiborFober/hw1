/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
	if (in == nullptr) // Base case
		return;

	Node* nextNode = in->next; // Store next node before modifying `in`

	if (in->value % 2 == 0) // Even number
	{
		in->next = evens;
		evens = in;
	}
	else // Odd number
	{
		in->next = odds;
		odds = in;
	}

	in = nullptr;

	split(nextNode, odds, evens);
}

/* If you needed a helper function, write it here */
