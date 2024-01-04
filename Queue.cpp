#include <iostream>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

using namespace std;


struct SNode 
{
	int nData;
	SNode* pNext;
};

SNode* Push(SNode* pStart, int data);
SNode* Pop(SNode* pStart);
template<typename T>
T Front(SNode* pStart);
template<typename T>
T Back(SNode* pStart);
bool Empty(SNode* pStart);
int Size(SNode* pStart);

void PrintQueue(SNode* pStart);

int main()
{

	SNode* pBegin = NULL; // queue의 시작주소
	SNode* pEnd = NULL;

	pEnd = Push(pEnd, 10);
	pBegin = pEnd;

	if (Empty(pBegin))
		cout << "Empty True" << endl;
	else
		cout << "Empty False" << endl;

	cout << "Size : " << Size(pBegin) << endl;

	pEnd = Push(pEnd, 20);
	pEnd = Push(pEnd, 30);
	pEnd = Push(pEnd, 40);
	pEnd = Push(pEnd, 50);


	PrintQueue(pBegin);
	cout << "Size : " << Size(pBegin) << endl;

	pBegin = Pop(pBegin);
	PrintQueue(pBegin);

	pEnd = Push(pEnd, 10);
	PrintQueue(pBegin);

	cout << "Front:" << Front(pBegin) << endl;
	cout << "Back:" << Back(pBegin) << endl;
	PrintQueue(pBegin);
	Empty(pBegin);

	pBegin = Pop(pBegin);
	PrintQueue(pBegin);
	pEnd = Push(pEnd, 20);
	PrintQueue(pBegin);

	cout << "Size : " << Size(pBegin) << endl;
	
	while (Size(pBegin) >0)
	{
		pBegin = Pop(pBegin);
	}

	cout << "Size : " << Size(pBegin) << endl;
	if (Empty(pBegin))
		cout << "Empty True" << endl;
	else
		cout << "Empty False" << endl;

}

SNode* Push(SNode* pStart, int data)
{
	cout << "Push" << endl;
	SNode* pTemp;

	pTemp = new SNode();
	pTemp->nData = data;

	if (pStart != nullptr)
	{
		pStart->pNext = pTemp;
	}

	return pTemp;
}

SNode* Pop(SNode* pStart)
{
	cout << "Pop" << endl;

	SNode* pNode = pStart ->pNext;
	SNode* pDel = pStart;
	
	delete pDel;

	return pNode;
}

template <typename T>
T Front(SNode* pStart)
{
	return pStart->nData;
}

template <typename T>
int Back(SNode* pStart)
{
	SNode* pNode = pStart;
	int data = pStart->nData;

	while (pNode)
	{
		data = pNode->nData;
		pNode= pNode->pNext;
	}

	return data;
}

bool Empty(SNode* pStart)
{
	SNode* pNode = pStart;
	if (pStart == NULL)
		return true;
	else
		return false;
}

int Size(SNode* pStart)
{
	SNode* pNode=pStart;
	int count = 0;
	while (pNode)
	{
		pNode = pNode->pNext;
		count++;
	}


	return count;
}

void PrintQueue(SNode* pStart)
{
	SNode* pNode = pStart;
	cout << "data:";
	while (pNode)
	{
		cout << pNode->nData;
		pNode = pNode->pNext;

		if (pNode != nullptr)
		{
			cout << ",";
		}
	}
	cout << endl;

}