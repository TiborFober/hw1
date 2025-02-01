#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite
void printListState(ULListStr& list) 
{
	cout << "Size: " << list.size() << " | ";
	if (!list.empty()) {
		cout << "Front: " << list.front() << " | Back: " << list.back();
	}
	cout << endl;
}


int main(int argc, char* argv[])
{
	ULListStr list;

	cout << "=== TESTING ULListStr IMPLEMENTATION ===" << endl;

	// push_back on an empty list
	cout << "Pushing back 'A'..." << endl;
	list.push_back("A");
	assert(list.size() == 1);
	assert(list.front() == "A");
	assert(list.back() == "A");
	printListState(list);

	// push_back with multiple elements
	cout << "Pushing back 'B', 'C', 'D' etc" << endl;
	list.push_back("B");
	list.push_back("C");
	list.push_back("D");
	assert(list.size() == 4);
	assert(list.front() == "A");
	assert(list.back() == "D");
	printListState(list);

	// push_front on a non-empty list
	cout << "Pushing front 'Z' etc" << endl;
	list.push_front("Z");
	assert(list.size() == 5);
	assert(list.front() == "Z");
	assert(list.back() == "D");
	printListState(list);

	//pop_back until empty
	cout << "Popping back elements etc" << endl;
	while (!list.empty()) 
	{
		cout << "Popping back: " << list.back() << endl;
		list.pop_back();
		printListState(list);
	}
	assert(list.empty());

	// push_front on an empty list
	cout << "Pushing front 'X'" << endl;
	list.push_front("X");
	assert(list.size() == 1);
	assert(list.front() == "X");
	assert(list.back() == "X");
	printListState(list);

	// pop_front
	cout << "Popping front: " << list.front() << endl;
	list.pop_front();
	assert(list.empty());
	printListState(list);

	// Fill the list with ARRSIZE elements to test node allocation
	cout << "Filling list with ARRSIZE elements" << endl;
	for (int i = 0; i < 10; ++i)
	{
		list.push_back(to_string(i));
	}

	assert(list.size() == 10);
	assert(list.front() == "0");
	assert(list.back() == "9");
	printListState(list);

	//get() method
	cout << "Checking get() method" << endl;
	for (size_t i = 0; i < list.size(); ++i) 
	{
		assert(list.get(i) == to_string(i));
	}
	cout << "All get() tests passed!" << endl;

	// pop_front multiple times
	cout << "Popping front multiple times" << endl;
	for (int i = 0; i < 5; ++i) 
	{
		cout << "Popping front: " << list.front() << endl;
		list.pop_front();
		printListState(list);
	}

	// emptying the list completely
	cout << "Emptying the list" << endl;
	while (!list.empty()) 
	{
		list.pop_front();
		printListState(list);
	}
	assert(list.empty());

	cout << "Tests have been completed succesfully!" << endl;
	return 0;
}

