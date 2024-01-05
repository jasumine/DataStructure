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
int Top(SNode* pStart);
bool Empty(SNode* pStart);
int Size(SNode* pStart);
void PrintStack(SNode* pStart);

void main()
{
	SNode* pBegin = NULL;
	SNode* pEnd = NULL;

	if (Empty(pBegin))
		cout << "Empty: true" << endl;
	else
		cout << "Empty: false" << endl;

	cout << "size:" << Size(pBegin) << endl;

	pEnd = Push(pEnd, 10);
	pBegin = pEnd;

	pEnd = Push(pEnd, 20); 
	pEnd = Push(pEnd, 30); 
	pEnd = Push(pEnd, 40);
	pEnd = Push(pEnd, 50);

	PrintStack(pBegin);
	cout << "Top:" << Top(pBegin) << endl;
	
	Pop(pBegin);
	
	cout << "Top:" << Top(pBegin) << endl;
	PrintStack(pBegin);

	if (Empty(pBegin))
		cout << "Empty: true" << endl;
	else
		cout << "Empty: false" << endl;

	cout << "size:" << Size(pBegin) << endl;

	Pop(pBegin);
	Pop(pBegin);
	Pop(pBegin);
	Pop(pBegin);

	if (Empty(pBegin))
		cout << "Empty: true" << endl;
	else
		cout << "Empty: false" << endl;

	cout << "size:" << Size(pBegin) << endl;
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
	cout << "Pop" << endl;

	SNode* pNode = pStart;
	SNode* pPre = NULL;

	if (pNode->pNext != nullptr)
	{
		while(pNode->pNext)
		{
			pPre = pNode;
			pNode = pNode->pNext;
		}
		pPre->pNext = nullptr;
		delete pNode;
	}
	else
	{
		pNode = nullptr;
		delete pNode;
	}
	
}

int Top(SNode* pStart)
{
	SNode* pNode = pStart;

	while (pNode->pNext)
	{
		pNode= pNode->pNext;
	}

	return pNode->nData;
}

bool Empty(SNode* pStart)
{
	SNode* pNode = pStart;
	
	if (pStart == nullptr)
		return true;
	else
		return false;
}

int Size(SNode* pStart)
{
	SNode* pNode = pStart;
	int count = 0;

	if (pNode != nullptr)
	{
		while (pNode->pNext != nullptr)
		{
			count++;
			pNode = pNode->pNext;
		}

		return count;
	}
	else
	{
		return count;
	}

}
 

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
