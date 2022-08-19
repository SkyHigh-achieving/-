#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

//bug
//P41.15
//��֪��������A��B�ֱ��ʾ��������, ��Ԫ�ص������С����ƺ���, ��A��B�Ľ�
//��, �������A������

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region ������ͷ��������

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ������
bool InitList(LinkList& L) {
	//����һ��ͷ���
	L = (LNode*)malloc(sizeof(LNode));
	//�ڴ治�㣬����ʧ��
	if (L == NULL) {
		return false;
	}
	//ͷ���֮����ʱ��û�нڵ�
	L->next = NULL;
	return true;
}


//�ж��Ƿ�Ϊ��
bool IsEmpty(LinkList L) {
	return ((L->next) == NULL);
}

//ʹ��β�巨����
LinkList CreatList(vector<int> data) {
	if (data.size() < 1) {
		return NULL;
	}
	//ͷ���
	LNode* head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList p = head;
	_for(i, 0, data.size()) {
		LNode* s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
	return head;
}
//�������
void PrintList(LinkList list) {
	if (IsEmpty(list)) {
		cout << "the list is null" << endl;
		return;
	}
	list = list->next;
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

int Getlen(LinkList L) {
	int len = 0;
	while (L != NULL) {
		L = L->next;
		len++;
	}
	return len;
}
#pragma endregion

void GetCommonList(LinkList& A, LinkList& B) {
	LinkList pa = A->next;
	LinkList pb = B->next;
	LinkList pre = A;
	while (pa && pb) {
		if (pa->data == pb->data) {
			pre->next=pa;
			pre = pa;
			pa = pa->next;
			LNode* u = pb;
			pb = pb->next;
			delete u;
		}
		else if (pa->data < pb->data) {
			LNode* u = pa;
			pa = pa->next;
			delete u;
		}
		else {
			LNode* u = pb;
			pb = pb->next;
			delete u;
		}
	}
	while (pa) {
		LNode* u = pa;
		pa = pa->next;
		delete u;
	}
	while (pb) {
		LNode* u = pb;
		pb = pb->next;
		delete u;
	}
	PrintList(A);
	PrintList(B);
}
int main() {
	vector<int> data1{ 1,3,5,7,9,11 };
	vector<int> data2{ 1,4,5,9 };
	LinkList A;
	InitList(A);
	LinkList B;
	InitList(B);
	A = CreatList(data1);
	B = CreatList(data2);
	PrintList(A);
	PrintList(B);
	GetCommonList(A, B);
	//PrintList(A);
	return 0;
}