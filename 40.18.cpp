#include<iostream>
#include<vector>

using namespace std;
#define ElemType int 
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f
//单链表 Single List翻译的真的感觉不对
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
//P42.18
//有两个循环单链表, 链表头指针分别为h1和h2, 编写一个函数将链表h2链接到链表
//h1之后, 要求链接后的链表仍保持循环链表形式

//LinkList Merger(LinkList& A,LinkList& B) {
//	LNode* p=A->next, * q=B->next;
//	for (; p->next != A; p = p->next);
//	for (; q->next != B; q = q->next);
//	p->next = B->next;
//	q->next = A;
//	return A;
//}

LinkList Merger(LinkList& h1, LinkList& h2) {//h1	0x01361328 {data=-842150451 next=0x013612b8 {data=1 next=0x01361210 {data=3 next=0x013610c0 {data=5 ...} } } }	LNode * &
	
	LNode* p, * q;
	p = h1;

	while (p ->next!= h1) {//如果不->next直接就跳过去了
		p = p->next;

	}//+p	0x01360e20 {data=1 next=0x01361328 {data=-842150451 next=0x013612b8 {data=1 next=0x01361210 {data=3 ...} } } }	LNode *

	q = h2;
	while (q->next != h2) {
		q = q->next;
	}
	p->next = h2->next;//绝对不能指向h2,否则这个个会把h2的头结点一起打印出来，这个结点里面的数据是无效的。
	q ->next= h1;
	return h1;
}
int main() {
	cout << "Please Enter your Node\n"<<endl;
	vector<int> data1{ 1,3,5,9,7,1 };
	vector<int> data2{ 2,4,6,8,4,2 };
	LinkList A;
	InitList(A);
	A = CreatList(data1);
	PrintList(A);
	LinkList B;
	InitList(B);
	B = CreatList(data2);
	PrintList(B);
	cout << "Test Results is:\n" << endl;
	A = Merger(A, B);
	PrintList(A);
	return 0;
}