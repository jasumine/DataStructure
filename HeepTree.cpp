// Heap ��(�� Ʈ��)
// �θ� �ڽ��� ������ �۾ƾ��Ѵ� -> �ּ� ��Ʈ��
// �θ� �ڽ��� ������ Ŀ���Ѵ� -> �ִ� ��Ʈ��

/*##################################
����Ʈ��(C��� ������)
���ϸ�: BinaryTree.cpp
�ۼ��� : ��ȫ��(downkhg@gmail.com)
������������¥ : 2022.03.04
���� : 1.01
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
	printf("%d\n", pNode->nData); //����
	Traverse(pNode->pLeft);
	//printf("%d\n", pNode->nData); //����
	Traverse(pNode->pRight);
	//printf("%d\n", pNode->nData); //����
}
void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

bool FindLeftNode(SNode* pNode)
{
	// null�� ã���� true
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
	// null�� ã���� true
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
	// node�� �ּҺ��� �����ؼ� ���� ������ �˻�
	// 1���� ->				�θ� 
	// 2���� ->		�ڽ�1		�ڽ�2
	// 3���� -> �ڽ�3 �ڽ�4	�ڽ�5	�ڽ�6
	// �θ��� left�� right�� �˻��Ѵ�.-> ������� �ʴٸ�,
	// �ڽ�1�� �θ� �Ǿ -> left�� right�� �˻��Ѵ�.
	
	SNode* pParent = pNode;
	SNode* pTemp = NULL;
	pTemp->nData = _data;

	while (!FindNullNode(pNode))
	{
		// FindNullNode�� ���� false��� while���� �ݺ�,
		// FindNullNode�� ���� true��� while���� Ż��
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