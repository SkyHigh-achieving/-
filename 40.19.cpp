#include<iostream>
#include<vector>

using namespace std;
#define ElemType int 
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f
//������ Single List�������ĸо�����
#pragma region

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	if (L== NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

bool IsEmpty(LinkList L) {
	return (L->next == NULL);
}

bool IsTail(LinkList L,LNode *p) {
	return(p->next == L);
}

LinkList CreatList(vector<int>data) {
	if (data.size() < 1) {
		return NULL;
	}
	LinkList head= (LinkList)malloc(sizeof(LNode));
	head -> next = NULL;
	LinkList p = head;//-		head	0x01361328 {data=-842150451 next=0x013612b8 {data=1 next=0x01361210 {data=3 next=0x013610c0 {data=5 ...} } } }	LNode *
	//head is not set to NULL
	_for(i, 0, data.size()) {
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
	p->next = head;
	p = head;
	return head;
}

void PrintList(LinkList L) {
	if (IsEmpty(L)) {
		cout << "the list is null\n" << endl;
		return;
	}
	LinkList pL = L->next;
	while (pL->next != L->next) {//L->next
		printf("%d ", pL->data);//pL
		pL = pL->next;
	}
	printf("\n");
}

int GetLen(LinkList L) {
	int Len = 0;
	while (L != NULL) {
		Len++;
		L = L->next;
	}
	return Len;
}
#pragma endregion
//P42.19
//����һ����ͷ����ѭ������������ֵ��Ϊ�����������һ���㷨�������ҳ�����
//���н��ֵ��С�Ľ�㲢�����Ȼ�󽫸ý�����ɾ��, ֱ���������Ϊֹ����ɾ����
//ͷ��㡣

void DelMinPrint(LinkList& A) {
	LinkList p = A->next;
	LinkList pre = A;
	LinkList Min = p;
	LinkList Minpre = A;
	while (A->next != A) {
		p = A->next;
		pre = A;
		Min = p;
		Minpre = A;
		while (p != A) {
			if (p->data < Min->data) {
				Min = p;
				Minpre = pre;
			}
			else {
				p = p->next;
				pre = pre->next;
			}
		}
		Minpre->next = Min->next;
		cout << Min->data <<" " << endl;
		delete Min;
	}
}

int main() {
	cout << "��������:" << endl;
	vector<int> data1{ 1,3,5,9,7,2 };
	LinkList A;
	InitList(A);
	A = CreatList(data1);
	PrintList(A);
	cout << "���Խ��:" << endl;
	DelMinPrint(A);
	PrintList(A);
	return 0;
}