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

	LinkedList(); //������
	void InitList(); //�ʱ�ȭ

	Node* Find(List*, Node*); //���� �����͸� ������ ��� ã��
	void InsHead(int); //������ ����(����)
	void InsTail(int); //���ϳ�� ����(����)
	void InsAfterCur(int);//���� ��� �ڿ� ��� ����
	void RemHead(); // ��� ��� ����
	void RemCur(); // ���� ��� ����
	void PrintCur(); // ���ó�� ���
	void PrintAll(); //��� ��� ���

};

