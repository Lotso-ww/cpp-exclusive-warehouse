//#pragma once
//
//typedef struct SeqList 
//{
//	int* arr;
//	int size;
//	int capacity;
//}SL;
//
//void SLInit(SL* pls,int n=4);
//void SLPushBack(SL* pls, int x);
//int SLFind(SL* pls, int x,int i=0);


#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct SeqList
{
	int* arr;
	int size;
	int capacity;

}SL;

void SLInit(SL& pls, int n = 4);
void SLPushBack(SL& pls, int x);
int SLFind(SL& pls, int x, int i = 0);
int& SLat(SL& pls, int i);//这里使用引用就又可以读取i位置的值，又可以修改了
void SLModify(SL& pls, int i, int x);//这个并不好用
