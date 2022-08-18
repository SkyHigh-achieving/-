#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

//41.12��һ��������������Ա�������ֵ��ͬ��Ԫ�ش��ڡ��洢��ʽΪ����������㷨
//ȥ����ֵ��ͬ��Ԫ�أ��Ǳ��в������ظ���Ԫ�أ�����{4��10��10......}
#define ElemType int 
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList& L)
{
	L = (LinkList)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}

bool IsEmpty(LinkList L) {
	return((L->next) == NULL);
}

//tail
LinkList CreatList(vector<int>data) {
	if (data.size() < 1) {
		return NULL;
	}
	LNode*head= (LinkList)malloc(sizeof(LNode));
	head->data = NULL;
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

void PrintList(LinkList L) {
	if (IsEmpty(L)) {
		cout << "Empty!\n"<<endl;
		return;
	}
	L = L->next;
	while (L != NULL) {
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
#pragma endregion

////40.12
//void Del_Same(LinkList& L) {
//	LNode* p = L->next,*q;
//	if (p == NULL) {
//		return;
//	}
//	while (p->next != NULL) {//
//		q = p->next;
//		if (p->data == q->data) {
//			p->next = q->next;
//			free(q);
//		}
//		else {
//			p = p->next;
//		}
//	}
//}

//P41.13
//������������Ԫ��ֵ�����������е����Ա�, ���Ե�������ʽ�洢�����д�㷨������
//��������鲢Ϊһ����Ԫ��ֵ�ݼ��������еĵ�����, ��Ҫ������ԭ������������Ľ�
//���Ź鲢��ĵ�����

void Consolidation(LinkList& A, LinkList& B) {
	LinkList pa = A->next;
	LinkList pb = B->next;
	LinkList prea = A;
	LinkList preb = B;
	prea->next = NULL;
	while (pa && pb) {
		if (pa->data < pb->data) {//head r->A
			LinkList r = pa -> next;
			LNode* x = pa;
			x->next = prea->next;
			prea->next = x;
			pa = r;
		}
		else {
			LinkList r = pb->next;
			LNode* x = pb;
			x->next = prea->next;
			prea->next = x;
			pb = r;
		}
	}
	if (pa) {
		pb = pa;
	}
	while (pb) {
		LinkList r = pb->next;
		LNode* x = pb;
		x->next = prea->next;
		prea->next = x;
		pb = r;
	}
}
int main() {
	/*vector<int>data{ 7,10,10,21,30,42,42,42,53,70 };*/
	vector<int> data1{ 1,3,5,7,9,11 };
	vector<int> data2{ 2,4,6,8 };
	LinkList A;
	InitList(A);
	LinkList B;
	InitList(B);
	A = CreatList(data1);
	B = CreatList(data2);
	PrintList(A);
	PrintList(B);
	////40.12
	//Del_Same(head);
	Consolidation(A, B);
	PrintList(A);	
	return 0;
}