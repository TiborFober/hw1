/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

using namespace std;

// Helper function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node{arr[0], nullptr};
    Node* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = new Node{arr[i], nullptr};
        current = current->next;
    }
    
    return head;
}

// Helper function to delete a linked list to prevent memory leaks
void deleteList(Node* &head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example input: a sorted linked list
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};
    Node* in = createList(arr, 10);

    // Display original list
    cout << "Original list: ";
    printList(in);

    // Pointers for the resulting lists
    Node* odds = nullptr;
    Node* evens = nullptr;

    // Call the split function
    split(in, odds, evens);

    // Display results
    cout << "Odds list: ";
    printList(odds);

    cout << "Evens list: ";
    printList(evens);

    // Cleanup to avoid memory leaks
    deleteList(odds);
    deleteList(evens);

    return 0;
}