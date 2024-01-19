// Heap 힙(힙 트리)
// 부모가 자식의 값보다 작아야한다 -> 최소 힙트리
// 부모가 자식의 값보다 커야한다 -> 최대 힙트리

/*##################################
이진트리(C언어 수업용)
파일명: BinaryTree.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.04
버전 : 1.01
###################################*/
#include <stdio.h>

using namespace std;

struct SNode {
	int nData;
	SNode* pLeft;
	SNode* pRight;
};

SNode* CreateNode(int data)
{
	SNode* pTemp = new SNode;
	pTemp->nData = data;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	return pTemp;
};

bool MakeLeft(SNode* pParent, SNode* pChilde)
{
	if (pParent == NULL)
		return false;
	pParent->pLeft = pChilde;
	return true;
};

bool MakeRight(SNode* pParent, SNode* pChilde)
{
	if (pParent == NULL)
		return false;
	pParent->pRight = pChilde;
	return true;
};

void Traverse(SNode* pNode)
{
	if (!pNode) return;
	printf("%d\n", pNode->nData); //전위
	Traverse(pNode->pLeft);
	//printf("%d\n", pNode->nData); //중위
	Traverse(pNode->pRight);
	//printf("%d\n", pNode->nData); //후위
}
void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

bool FindLeftNode(SNode* pNode)
{
	// null을 찾으면 true
	SNode* pParent = pNode;
	if (pParent->pLeft == NULL || pParent->pRight == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FindRighttNode(SNode* pNode)
{
	// null을 찾으면 true
	SNode* pParent = pNode;
	if (pParent->pLeft == NULL || pParent->pRight == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void InsertNode(SNode* pNode, int _data)
{
	// node의 주소부터 시작해서 왼쪽 오른쪽 검사
	// 1레벨 ->				부모 
	// 2레벨 ->		자식1		자식2
	// 3레벨 -> 자식3 자식4	자식5	자식6
	// 부모의 left와 right를 검사한다.-> 비어있지 않다면,
	// 자식1이 부모가 되어서 -> left와 right를 검사한다.
	
	SNode* pParent = pNode;
	SNode* pTemp = NULL;
	pTemp->nData = _data;

	while (!FindNullNode(pNode))
	{
		// FindNullNode의 값이 false라면 while문을 반복,
		// FindNullNode의 값이 true라면 while문을 탈출
		pParent = pNode->pLeft;
		
	}


}

bool FindNullNode(SNode* pNode)
{
	SNode* pParent = pNode;

	bool isFind = FindLeftNode(pParent);
	if (isFind == false)
	{
		isFind = FindRighttNode(pParent);
	}

	return isFind;
}




int main()
{
	SNode* pSeed = NULL;

	SNode* pParent = CreateNode(10);
	SNode* pLeft = CreateNode(20);
	SNode* pRight = CreateNode(30);
	SNode* pD = CreateNode(40);
	SNode* pE = CreateNode(50);

	MakeLeft(pParent, pLeft);
	MakeRight(pParent, pRight);

	MakeLeft(pLeft, pD);
	MakeRight(pLeft, pE);

	pSeed = pParent;

	Print(pSeed);
}