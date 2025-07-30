#pragma once
#include<iostream>

class Stack
{
public:
	void Init(int capacity = 4);
	void Push(int x);
private:
	int* _a;
	int _top;
	int _capacity;
};

