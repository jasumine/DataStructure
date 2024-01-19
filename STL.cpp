/*##################################
STL(자료구조 수업용)
파일명: STL_empty.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.09
버전 : 1.05
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
#include <unordered_map>//hash_map -> unordered_map: vs2019부터 변경
using namespace std;
//벡터: 동적배열
//0.배열은 데이터가 저장될공간이 미리 확보되어있다.
//1.인덱스로 원소접근이 가능하다.
//2.각 자료는 포인터연산(인덱스)을 통한 순차/랜덤접근이 가능하다.
//3.배열의 크기를 런타임중에 변경가능하다.
void VectorMain()
{
	vector<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	container[0] = 10;

	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.resize(3); //배열의 크기를 지정한다.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	//1.추가 2.삽입 3.삭제 4.모두삭제
	vector<int>::iterator it;

	// 1. 추가
	cout << "Add:";
	container.push_back(20);

	// 2. 삽입 - node와 data를 구분하기 위해서 iterator를 사용하는 것 

	// begin은 0번째 주소를 의미하므로, insert는 begin[0]에 값을 넣는것.
	vector<int>::iterator insert = container.begin();
	cout << "insert:" << *insert << endl;
	container.insert(insert, 30);

	// begin은 0번째 앞의 주소이고, begin() +1 은 0번째 값 다음의 주소이다.
	vector<int>::iterator moveN = container.begin() + 4;
	cout << "MoveN: " << *moveN << endl;

	// end는 마지막 값 끝의 주소이고 push_back이 되는 주소라고 보면됨.
	// end-1은 마지막 값 바로 앞의 주소
	vector<int>::iterator movePre = container.end() - 1;
	cout << "movePre : " << *movePre << endl;


	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.clear(); //모두삭제
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}


//연결리스트
//1.데이터는 순차접근만 가능하다.(랜덤x) -> 랜덤엑세스 X
//2.연결리스트에 추가,삽입,삭제은 O(1)이다.
//3.연결리스트의 종류: 단일, 환형, 이중 stl의 리스트는 어디에 해당되는가?
void ListMain()
{

	list<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	*container.begin() = 10;

	list<int>::iterator it;
	cout << "Print:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.resize(3); //배열의 크기를 지정한다.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << *container.begin()+i << ",";
	cout << endl;

	//1.추가 2.삽입 3.삭제 4.모두삭제
	//list<int>::iterator it;

	// 1. 추가
	cout << "Add:";
	container.push_back(20);

	// 2. 삽입 - node와 data를 구분하기 위해서 iterator를 사용하는 것 

	// begin은 0번째 주소를 의미하므로, insert는 begin[0]에 값을 넣는것.
	list<int>::iterator insert = container.begin();
	cout << "insert:" << *insert << endl;
	container.insert(insert, 30);

	// begin은 0번째 앞의 주소이고, begin() +1 은 0번째 값 다음의 주소이다.
	list<int>::iterator moveN = container.begin();
	moveN++; moveN++; moveN++;
	cout << "MoveN: " << *moveN << endl;

	// end는 마지막 값 끝의 주소이고 push_back이 되는 주소라고 보면됨.
	// end-1은 마지막 값 바로 앞의 주소
	list<int>::iterator movePre = container.end();
	movePre--;
	cout << "movePre : " << *movePre << endl;


	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.clear(); //모두삭제
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;
}


//데크: 앞뒤로 자료를 추가/삭제가능, 랜덤접근가능.
void DequeMain()
{
	// 양쪽으로 배열이 있다. -2 -1 0(시작주소) 1 2  이런느낌..?
	deque<int> container(1);//컨테이너생성시 크기를 지정가능하다.
	container[0] = 10;

	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	container.resize(3); //배열의 크기를 지정한다.
	cout << "Print:";
	for (int i = 0; i < container.size(); i++)
		cout << "[" << i << "]" << container[i] << ",";
	cout << endl;

	//1.추가 2.삽입 3.삭제 4.모두삭제
	deque<int>::iterator it;

	// 1. 추가
	cout << "Add:";
	container.push_back(20);

	// 2. 삽입 - node와 data를 구분하기 위해서 iterator를 사용하는 것 

	// begin은 0번째 주소를 의미하므로, insert는 begin[0]에 값을 넣는것.
	deque<int>::iterator insert = container.begin();
	cout << "insert:" << *insert << endl;
	container.insert(insert, 30);

	// begin은 0번째 앞의 주소이고, begin() +1 은 0번째 값 다음의 주소이다.
	deque<int>::iterator moveN = container.begin() + 4;
	cout << "MoveN: " << *moveN << endl;

	// end는 마지막 값 끝의 주소이고 push_back이 되는 주소라고 보면됨.
	// end-1은 마지막 값 바로 앞의 주소
	deque<int>::iterator movePre = container.end() - 1;
	cout << "movePre : " << *movePre << endl;


	cout << "PrintPtr:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

	container.clear(); //모두삭제
	cout << "Clear:";
	for (it = container.begin(); it != container.end(); it++)
		cout << "[" << &*it << "]" << *it << ",";
	cout << endl;

}
//스택: 뒤에서 추가되고 뒤에서 꺼냄.
//재귀함수에서 이전 함수를 호출할때마다 스택에 쌓임.
//문자열뒤집기 -> 문자배열 -> apple -> elppa
void StackMain()
{

}
//큐: 뒤에서 추가하고 앞에서 꺼냄.
//메세지큐: 이벤트가 발생한 순서대로 저장하는 공간.
//입력된 순서대로 명령어 처리하기
void QueueMain()
{

}
//우선순위큐: 우선순위가 높은 원소가 먼저나감(힙)
//무작위로 데이터를 넣었을때 어떤 순서대로 데이터가 나오는가? 큰값부터 나온다.
void PriorytyQueueMain()
{
	//어렵다크래용 한번해보기
}
//맵: 사전식으로 데이터를 찾을수있다.
//해당영어단어를 넣으면 한국어 결과가 나온다.
void MapMain()
{
	map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

	cout << mapDic["try"] << endl;
	cout << mapDic["note"] << endl;
}
//셋: 순서없이 데이터를 넣는다. 데이터는 순서와 상관없이 데이터를 찾는다.
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
//해시맵: 해시테이블 -> 가장빠를 수 있고, 가장 느릴 수 있음!
// 해시함수를 이용해서 해시맵만들기.
void HashMapMain()
{
	unordered_map<string, string> mapDic;

	mapDic["test"] = "시험";
	mapDic["pratice"] = "연습";
	mapDic["try"] = "도전";
	mapDic["note"] = "기록";

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