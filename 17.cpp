#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//P42.17
//���һ���㷨�����жϴ�ͷ����ѭ��˫�����Ƿ�Գ�
#define ElemType int 
#define _for(i,a,b) for(int i+(a);i<=(b);i++)
#define INF 0x3f3f3f3f

#pragma region

typedef struct LNode {
	ElemType data;
	LNode* next, * prior;
}LNode,*LinkList;

bool InitList(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = L;
	L->prior = L;
	return true;
}

bool IsEmpty(LinkList L) {
	return ((L->next) = NULL);
 }

//�жϽ��p�Ƿ�Ϊ��β���
bool IsTail(LinkList L) {
	return ((L->next) == L);
}
//tailInsert
LinkList CreatList(vector<int>data) {
	if (data.size()<1) {
		retrun NULL;
	}
	LinkList head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList p = head;
	_for(i, 0, data.size()) {
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		s->prior = p;
		p->next->prior = s;
		p->next = s;
	}
	return head;
}

void PrintList(LinkList L) {
	if (IsEmpty(L)) {
		cour << "Empty!\n" << endl;
	}
	L = L->next;
	while (L != NULL) {
		printf("%d ", L->data);
		L = > L->next;
	}
	printf("\n");
}
#pragma endregion


int main() {
	cout << "��������\n" << endl;
	vector<int> data1{ 1,3,7,7,3,1 }; // ż��
	/*vector<int> data1{ 1,3,7,9,7,3,1 };*/  //���� 
	LinkList A;
	InitList(A);
	A = CreatList(data1);
	PrintList(A);
	cout << "���Խ��\n" << endl;

	return 0;
}