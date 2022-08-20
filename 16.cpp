#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//P42.16
//������������A = a1,a2,a3��, an��B = b1, b2, b3, ��, bn�Ѿ�����������������, ���
//���㷨, �ж�����B�Ƿ�������A������������
#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region 

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

bool IsEmpty(LinkList& L) {
	return ((L->next) == NULL);
}

LinkList CreatList(vector<int>data) {
	if (data.size() < 1) {
		return NULL;
	}
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	//head->data = NULL;//***
	LinkList p =head;
	_for(i, 0, data.size()) {
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;//������ÿգ������������
		p->next = s;
		p = s;
	}
	return head;
}

void PrintList(LinkList L) {
	if (IsEmpty(L)) {
		cout << "Empty!\n" << endl;
		return;
	}
	L = L->next;
	while (L != NULL)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
#pragma endregion

bool Subsequences(LinkList& A, LinkList& B) {
	LNode* p = A->next,*pre=A,*q=B->next;
	while (p && q) {
		if (p->data == q->data) {
			p = p->next;
			q = q->next;
		}
		else {
			pre = pre->next;
			p = pre;
			q = q->next;
		}
	}
	if (q == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cout << "��������:" << endl;
	vector<int> data1{ 1,3,5,7,9,11 };
	vector<int> data2{ 3,5,7,9 };
	LinkList A, B;
	InitList(A); InitList(B);
	A = CreatList(data1); B = CreatList(data2);
	PrintList(A); PrintList(B);
	if (Subsequences(A,B)) {
		cout << "����B������A������\n" << endl;
	}
	else {
		cout << "����\n" << endl;
	}
	return 0;
}