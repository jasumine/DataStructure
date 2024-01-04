// 연결리스트로 stack만들기

#include <iostream>

using namespace std;

struct SNode
{
	int nData;
	SNode* pNext;
};

SNode* Push(SNode* pStart, int data);
void Pop(SNode* pStart);
bool Empty(SNode* pStart);
int Size(SNode* pStart);
template<typename T> T top(SNode* pStart);
void PrintStack(SNode* pStart);

void main()
{
	SNode* pBegin = NULL;
	SNode* pEnd = NULL;

	pEnd = Push(pEnd, 10);
	pBegin = pEnd;

	pEnd = Push(pEnd, 20); 
	pEnd = Push(pEnd, 30); 
	pEnd = Push(pEnd, 40);
	pEnd = Push(pEnd, 50);

	PrintStack(pBegin);
	Pop(pBegin);
	PrintStack(pBegin);
}


SNode* Push(SNode* pStart, int data)
{
	SNode* pTemp = NULL;

	pTemp = new SNode();
	pTemp->nData = data;

	if (pStart != NULL)
	{
		pStart->pNext = pTemp;
	}

	return pTemp;
}

void Pop(SNode* pStart)
{
	SNode* pNode = pStart;
	SNode* pPre = NULL;

	while (pNode->pNext)
	{
		pPre = pNode;
		pNode = pNode->pNext;
	}
	pPre->pNext = nullptr;
	delete pNode;

}

bool Empty(SNode* pStart);
int Size(SNode* pStart);
template<typename T> T top(SNode* pStart);
void PrintStack(SNode* pStart)
{
	SNode* pNode = pStart;
	cout << "data:";
	while (pNode)
	{
		cout << pNode->nData;
		pNode = pNode->pNext;

		if (pNode != nullptr)
			cout << ", ";
	}
	cout << endl;
}
