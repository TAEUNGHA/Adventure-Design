#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* nextnode;
};

struct List
{
	Node* headnode;
	Node* curnode;
};

class LinkedList
{

public:

	List* list;

	LinkedList(); //생성자
	void InitList(); //초기화

	Node* Find(List*, Node*); //같은 데이터를 가지는 노드 찾기
	void InsHead(int); //헤더노드 변경(삽입)
	void InsTail(int); //테일노드 변경(삽입)
	void InsAfterCur(int);//선택 노드 뒤에 노드 삽입
	void RemHead(); // 헤더 노드 삭제
	void RemCur(); // 선택 노드 삭제
	void PrintCur(); // 선택노드 출력
	void PrintAll(); //모든 노드 출력

};

