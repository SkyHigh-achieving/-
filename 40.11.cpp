#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
//P41.11
//��C = { a1,b1,a2��b2,��,an��bn }Ϊ���Ա�, ���ô�ͷ����hc��������, ���һ���͵�
//�㷨, ������Ϊ�������Ա�, ʹ��A = { a1,a2��,an }, B = { bn,��,b2,b1 }

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList& head) {
	head = (LNode*)malloc(sizeof(LNode));
	if (head == NULL) {
		return false;
	}
	head->next = NULL;
	return true;
}

bool IsEmpty(LinkList L) {
	return((L->next) == NULL);
}

//tail
LinkList CreatList(vector<int> data) {
	if (data.size() < 1) {
		return NULL;
	}
	LNode* head = (LinkList)malloc(sizeof(LNode));
	head->data = NULL;
	head->next = NULL;
	LNode* p = head;
	_for(i, 0, data.size()) {
		LNode* s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
	return head;
}

void PrintList(LinkList L) {
	if (IsEmpty(L)) {
		cout << "Empty\n" << endl;
		return;
	}
	L = L->next;
	while (L != NULL) {//�����L->next,�ڵ����ڶ�����ͣ������
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
#pragma endregion

void DisCreate(LinkList& A) {
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode* p = A->next, * q;//���pָ��A���ͱ��ͷ�ڵ���
	LNode* ra = A;
	while (p != NULL) {
		ra->next = p;
		ra = p;
		p = p->next;
		if (p != NULL) {
			q = p->next;
			p->next = B->next;
			B->next = p;
			p = q;
		}
	}
	ra->next = NULL;
	cout << "A: " << endl;
	PrintList(A);
	cout << "B: " << endl;
	PrintList(B);
}
int main() {
	vector<int>data{ 1,2,3,4,5,6,7,8 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	DisCreate(head);
	return 0;
}