#pragma once

#include <string>
#include <iostream>
using namespace std;

class node {
public:
	node* next = nullptr;
	node* prev = nullptr;
	node* headPtr = nullptr;
	node* tailPtr = nullptr;

	int floor;

};

class elevator {
private:
	node* headPtr;
	node* tailPtr;
public:

	elevator();

	void insert(int i, int floor);
	void print();
	bool empty();
	void push_front(int floor);
};