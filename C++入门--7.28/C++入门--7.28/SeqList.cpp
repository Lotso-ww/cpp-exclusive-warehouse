//#define _CRT_SECURE_NO_WARNINGS 1
//#include"SeqList.h"
//
//void SLInit(SL* pls,int n)//如果确定n为多少就可以不用在声明时（.h）使用缺省函数,不确定可以初始化一下
//{
//	//………………
//	//初始化的时候malloc大小为n*sizoef(int)的数组
//}
//void SLPushBack(SL* pls, int x)
//{
//	//………………
//}
//int SLFind(SL* pls, int x,int i)//从n开始找，默认的时候缺省为0,在.h文件中看
//{
//	//……………………
// while (i < pls->size)
//  {
//	//………………
//  }
//
//	return -1;//没找到
//}

#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLInit(SL& pls,int n)
{
	pls.arr = (int*)malloc(n * sizeof(int));
	pls.size = 0;
	pls.capacity = n;
}

void SLPushBack(SL& pls, int x)
{
	//………………
	pls.arr[pls.size++] = x;
}

int SLFind(SL& pls, int x,int i)
{
	while (i < pls.size)
	{
		//………………
	}

	return -1;
}

int& SLat(SL& pls, int i)//这里使用引用就又可以读取i位置的值，又可以修改了
{
	//……
	return pls.arr[i];//这里可以使用引用返回是因为它是结构体中的一个在堆的数据
}
	
void SLModify(SL& pls, int i, int x)//这个并不好用
{
	//……
	pls.arr[i] = x;
}