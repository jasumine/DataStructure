/*##################################
STL(�ڷᱸ�� ������)
���ϸ�: STL_empty.cpp
�ۼ��� : ��ȫ��(downkhg@gmail.com)
������������¥ : 2022.03.09
���� : 1.05
###################################*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>//hash_map -> unordered_map: vs2019���� ����
using namespace std;
//����: �����迭
//0.�迭�� �����Ͱ� ����ɰ����� �̸� Ȯ���Ǿ��ִ�.
//1.�ε����� ���������� �����ϴ�.
//2.�� �ڷ�� �����Ϳ���(�ε���)�� ���� ����/���������� �����ϴ�.
//3.�迭�� ũ�⸦ ��Ÿ���߿� ���氡���ϴ�.
void VectorMain()
{
	vector<int> container(1);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	container[0] = 10;

	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.resize(3); //�迭�� ũ�⸦ �����Ѵ�.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	//1.�߰� 2.���� 3.���� 4.��λ���
	vector<int>::iterator it;

	// 1. �߰�
	cout << "Add:";
	container.push_back(20);

	// 2. ���� - node�� data�� �����ϱ� ���ؼ� iterator�� ����ϴ� �� 

	// begin�� 0��° �ּҸ� �ǹ��ϹǷ�, insert�� begin[0]�� ���� �ִ°�.
	vector<int>::iterator insert = container.begin();
	cout << "insert:" << *insert << endl;
	container.insert(insert, 30);

	// begin�� 0��° ���� �ּ��̰�, begin() +1 �� 0��° �� ������ �ּ��̴�.
	vector<int>::iterator moveN = container.begin() + 4;
	cout << "MoveN: " << *moveN << endl;

	// end�� ������ �� ���� �ּ��̰� push_back�� �Ǵ� �ּҶ�� �����.
	// end-1�� ������ �� �ٷ� ���� �ּ�
	vector<int>::iterator movePre = container.end() - 1;
	cout << "movePre : " << *movePre << endl;


	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.clear(); //��λ���
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}


//���Ḯ��Ʈ
//1.�����ʹ� �������ٸ� �����ϴ�.(����x) -> ���������� X
//2.���Ḯ��Ʈ�� �߰�,����,������ O(1)�̴�.
//3.���Ḯ��Ʈ�� ����: ����, ȯ��, ���� stl�� ����Ʈ�� ��� �ش�Ǵ°�?
void ListMain()
{

	list<int> container(1);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	*container.begin() = 10;

	list<int>::iterator it;
	cout << "Print:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.resize(3); //�迭�� ũ�⸦ �����Ѵ�.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << *container.begin()+i << ",";
	cout << endl;

	//1.�߰� 2.���� 3.���� 4.��λ���
	//list<int>::iterator it;

	// 1. �߰�
	cout << "Add:";
	container.push_back(20);

	// 2. ���� - node�� data�� �����ϱ� ���ؼ� iterator�� ����ϴ� �� 

	// begin�� 0��° �ּҸ� �ǹ��ϹǷ�, insert�� begin[0]�� ���� �ִ°�.
	list<int>::iterator insert = container.begin();
	cout << "insert:" << *insert << endl;
	container.insert(insert, 30);

	// begin�� 0��° ���� �ּ��̰�, begin() +1 �� 0��° �� ������ �ּ��̴�.
	list<int>::iterator moveN = container.begin();
	moveN++; moveN++; moveN++;
	cout << "MoveN: " << *moveN << endl;

	// end�� ������ �� ���� �ּ��̰� push_back�� �Ǵ� �ּҶ�� �����.
	// end-1�� ������ �� �ٷ� ���� �ּ�
	list<int>::iterator movePre = container.end();
	movePre--;
	cout << "movePre : " << *movePre << endl;


	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.clear(); //��λ���
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}


//��ũ: �յڷ� �ڷḦ �߰�/��������, �������ٰ���.
void DequeMain()
{
	// �������� �迭�� �ִ�. -2 -1 0(�����ּ�) 1 2  �̷�����..?
	deque<int> container(1);//�����̳ʻ����� ũ�⸦ ���������ϴ�.
	container[0] = 10;

	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.resize(3); //�迭�� ũ�⸦ �����Ѵ�.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	//1.�߰� 2.���� 3.���� 4.��λ���
	deque<int>::iterator it;

	// 1. �߰�
	cout << "Add:";
	container.push_back(20);

	// 2. ���� - node�� data�� �����ϱ� ���ؼ� iterator�� ����ϴ� �� 

	// begin�� 0��° �ּҸ� �ǹ��ϹǷ�, insert�� begin[0]�� ���� �ִ°�.
	deque<int>::iterator insert = container.begin();
	cout << "insert:" << *insert << endl;
	container.insert(insert, 30);

	// begin�� 0��° ���� �ּ��̰�, begin() +1 �� 0��° �� ������ �ּ��̴�.
	deque<int>::iterator moveN = container.begin() + 4;
	cout << "MoveN: " << *moveN << endl;

	// end�� ������ �� ���� �ּ��̰� push_back�� �Ǵ� �ּҶ�� �����.
	// end-1�� ������ �� �ٷ� ���� �ּ�
	deque<int>::iterator movePre = container.end() - 1;
	cout << "movePre : " << *movePre << endl;


	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.clear(); //��λ���
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

}
//����: �ڿ��� �߰��ǰ� �ڿ��� ����.
//����Լ����� ���� �Լ��� ȣ���Ҷ����� ���ÿ� ����.
//���ڿ������� -> ���ڹ迭 -> apple -> elppa
void StackMain()
{

}
//ť: �ڿ��� �߰��ϰ� �տ��� ����.
//�޼���ť: �̺�Ʈ�� �߻��� ������� �����ϴ� ����.
//�Էµ� ������� ��ɾ� ó���ϱ�
void QueueMain()
{

}
//�켱����ť: �켱������ ���� ���Ұ� ��������(��)
//�������� �����͸� �־����� � ������� �����Ͱ� �����°�? ū������ ���´�.
void PriorytyQueueMain()
{
	//��ƴ�ũ���� �ѹ��غ���
}
//��: ���������� �����͸� ã�����ִ�.
//�ش翵��ܾ ������ �ѱ��� ����� ���´�.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//��: �������� �����͸� �ִ´�. �����ʹ� ������ ������� �����͸� ã�´�.
void SetMain()
{
	set<int> setData;

	setData.insert(10);
	setData.insert(20);
	setData.insert(30);
	setData.insert(40);

	set<int>::iterator it = setData.find(10);

	if (it != setData.end()) it;
	for (it = setData.begin(); it != setData.end(); it++)
		cout << *it << ",";
	cout << endl;
}
//�ؽø�: �ؽ����̺� -> ������� �� �ְ�, ���� ���� �� ����!
// �ؽ��Լ��� �̿��ؼ� �ؽøʸ����.
void HashMapMain()
{
	unordered_map<string, string> mapDic;

	mapDic["test"] = "����";
	mapDic["pratice"] = "����";
	mapDic["try"] = "����";
	mapDic["note"] = "���";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
void main()
{
	//VectorMain();
	ListMain();
	//DequeMain();
	//StackMain();
	//QueueMain();
	//PriorytyQueueMain();
	//MapMain();
	//SetMain();
}