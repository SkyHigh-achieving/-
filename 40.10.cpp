//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//
//using namespace std;
////P41.10
////��һ����ͷ���ĵ�����A�ֽ�Ϊ������ͷ���ĵ�����A��B, ʹ��A���к���ԭ��
////�����Ϊ������Ԫ��, ��B���к���ԭ�������Ϊż����Ԫ��, �ұ��������˳�򲻱�
//
//#define ElemType int
//#define _for(i,a,b) for(int i=(a);i<(b);i++)
//#define INF 0x3f3f3f3f
//
//#pragma region  ������ͷ���ĵ�����
//
//typedef struct LNode {
//	ElemType data;
//	struct LNode* next;
//}LNode,*LinkList;
//
////��ʼ��������
//bool InitList(LinkList& head) {
//	//����һ��ͷ���
//	head = (LNode*)malloc(sizeof(LNode));
//	if (head == NULL) {
//		return false;//��head������NULL�ˣ�
//	}
//	//ͷ������û��
//	head->next = NULL;
//	return true;
//}
////
//bool IsEmpty(LinkList L){
//	return ((L->next )== NULL);
//}
////tail
//LinkList CreatList(vector<int >data) {
//	if (data.size() < 1) {
//		return NULL;
//	}
//	LNode* head= (LNode*)malloc(sizeof(LNode));
//	head->data = NULL;
//	head->next = NULL;
//	LinkList p = head;
//	_for(i, 0, data.size()) {
//		LNode* s = (LNode*)malloc(sizeof(LNode));
//		s->data = data[i];
//		s->next = NULL;
//		p->next = s;
//		p = s;
//	}
//	return head;
//}
//
//void PrintList(LinkList L) {
//	if (IsEmpty) {
//		cout << "This List is Null\n";
//	}
//	while (L->next != NULL) {
//		printf("%d ", L->next);
//		L = L->next;
//	}
//	printf("\n");
//}
//#pragma endregion
////
////void Split(LinkList& head) {
////	LinkList B = (LinkList)malloc(sizeof(LinkList));
////	B->next = NULL;
////	LinkList p=head->next;
////	LinkList pre=head;
////	LinkList Bp=B;
////	int i=0;
////	while (p != NULL) {
////		i++;
////		if (i % 2 == 0) {//p is what we want
////			LNode* q = p;
////			Bp->next = q;
////			Bp = q;
////			pre->next = p->next;
////		}
////		else {
////			pre = p;
////			p = p->next;
////		}
////		
////	}
////	cout << "A: " << endl;
////	PrintList(head);
////	cout << "B: " << endl;
////	PrintList(B);
////}
//
//
//
//void Split(LinkList& head) {
//	LinkList B = (LinkList)malloc(sizeof(LNode));
//	B->next = NULL;
//	LinkList p = head->next;
//	LinkList pre = head;
//	LinkList Bp = B;
//	int i = 0;
//	while (p != NULL) {
//		i++;
//		if (i % 2 == 0) {
//			LNode* q = p;
//			Bp->next = q;
//			Bp = q;
//			pre->next = p->next;
//		}
//		else {
//			pre = p;
//			p = p->next;
//		}
//	}
//	cout << "A:" << endl;
//	PrintList(head);
//	cout << "B:" << endl;
//	PrintList(B);
//}
//
//int main() {
//	vector<int>data{ 3,5,6,8,1,3,9,3 };
//	LinkList head;
//	InitList(head);
//	head = CreatList(data);
//	PrintList(head);
//	Split(head);
//	return 0;
//}
//
#include <iostream>
#include <vector>
using namespace std;

//P41.10
//��һ����ͷ���ĵ�����A�ֽ�Ϊ������ͷ���ĵ�����A��B, ʹ��A���к���ԭ��
//�����Ϊ������Ԫ��, ��B���к���ԭ�������Ϊż����Ԫ��, �ұ��������˳�򲻱�

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

#pragma endregion


//P41.10

void Split(LinkList& head) {
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LinkList p = head->next;
	LinkList pre = head;
	LinkList Bp = B;
	int i = 0;
	while (p != NULL) {
		i++;
		if (i % 2 == 0) {
			LNode* q = p;
			Bp->next = q;
			Bp = q;
			pre->next = p->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
	cout << "A:" << endl;
	PrintList(head);
	cout << "B:" << endl;
	PrintList(B);
}

int main()
{
	vector<int> data{ 3,5,6,8,1,3,9,3 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	Split(head);
	return 0;
}

//ע���������н��������Ԥ�ڣ��޸���