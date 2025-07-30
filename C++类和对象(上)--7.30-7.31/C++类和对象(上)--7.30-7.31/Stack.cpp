#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//一定要带Stack::去找
void Stack::Init(int capacity)
{
	_a = nullptr; // malloc
	_top = 0;
	_capacity = capacity;
}

void Stack::Push(int x)
{
	//...
}