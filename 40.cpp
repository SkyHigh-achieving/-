#include<iostream>
#include<vector>

using namespace std;
#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)//remember to define the int of i
#define INF 0X3F3F3F3F
//40.3 设L为带头结点的单链表，滨蟹算法实现从尾到头反向输出各个结点的值

//40.4 试 辨析而在带头节点的单链表中删除一个最小值结点的高效算法（假设最小值节点是唯一的）

//40.5试编写算法将带头节点的单链表就地逆置，所谓就地是指辅助空间复杂度为o(1)
//40.6 有一个带头节点的单链表，设计一个算法使其元素递增有序

#pragma region

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*Linklist;

//Init
bool InitList(Linklist& L) {
	L = (LNode*)malloc(sizeof(LNode));
	////内存不足，分配失败
	if (L == NULL) {
		return false;
	}
	////节点后面暂时没有结点
	L->next=NULL;
	return true;
}

//isempty
bool IsEmpty(Linklist L) {
	return ((L->next) == NULL);
}

//tailInsert
//Linklist CreatList(vector<int> data){
//	if (data.size() < 1) {
//		return NULL;
//	}
//	LNode* head = (Linklist)malloc(sizeof(LNode));
//	head->data = data[0];
//	head->next = NULL;
//	Linklist p = head;//老是记不住
//	_for(i, 1, data.size()) {
//		LNode* s = (Linklist)malloc(sizeof(LNode));
//		s->data = data[i];
//		s->next = NULL;
//		p->next = s;
//		p = s;//p is a auxiliary pointer
//	}
//	return head;
//}
Linklist CreatList(vector<int> data) {
	if (data.size() < 1) {
		return NULL;
	}
	//头结点
	LNode* head = (Linklist)malloc(sizeof(LNode));
	head->data = data[0];
	head->next = NULL;
	Linklist p = head;
	_for(i, 1, data.size()) {
		LNode* s = (Linklist)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
	return head;
}
//printout
void PrintList(Linklist list) {
	list = list->next;//因为是带头节点的，这一步和40.1旧不一样。
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;//problem solved
	}
	printf("\n");
}
#pragma endregion

//P40.1
//void DeleteXNode(Linklist& head, ElemType x) {
//	if (head == NULL) return;
//	if (head->data!= x) {
//		return DeleteXNode(head->next,x);
//	}
//
//	//find it ,and then head point to the Node that data==x
//	LNode* q = head;
//	head = head->next;
//	delete q;
//	return DeleteXNode(head, x);//if head is exchanged with head->next,any problem?//no need
//}

//40.3

//void R_Print(Linklist L) {//并不改变L的位序，所以不需要给地址
///	if (L->next != NULL) {
//		R_Print(L->next);
//	}
//	if (L != NULL) {
//		printf("%d ", L->data);
//	}
//}
//40.4
//void DelMinNode(Linklist& head) {
//	LNode* p = head->next;
//	LNode* ppre = head;
//	LNode* Minpre=ppre, * Minp=p;
//	while(p!=NULL){
//		if (p->data < Minp->data) {
//			Minp = p;
//			Minpre = ppre;
//		}
//		else {
//			ppre = p;
//			p = p->next;
//		}
//	}
//	
//	LNode* x = Minp;
//	Minpre->next = Minp->next;
//	Minp = Minp->next;
//	delete x;
//}

//void ReversrList(Linklist& head) {
//	LNode* pre, * p = head->next, * r = p->next;//pre 的目的是什么呢？
//	p->next = NULL;
//	while (r != NULL) {
//		pre = p;
//		p = r;
//		r = r->next;
//		p -> next = pre;
//	}
//	head->next = p;
//}
//void ReverseList(Linklist& head) {
//	LNode* pre=head, * p = head->next, * r = p->next;
//	p->next = NULL;
//	while (r != NULL) {
//		pre = p;
//		p = r;
//		r = r->next;
//		p->next = pre;
//	}
//	head->next = p;
//}

//40.6
void Sort(Linklist& L) {
	LNode* p = L->next, * pre;
	LNode* r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL) {
		r = p->next;
		pre = L;
		pre = L;
		while (pre->next != NULL && pre->next->data < p->data) {
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;//提前用r存储了这部分代码
	}
}
int main(){
	vector<int> data{ 3,4,6,8,1,3,9,5};
	Linklist head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	/*DeleteXNode(head, 6);*/
	
	//40.3
	/*R_Print(head);*/
	/*PrintList(head);*/
	//DelMinNode(head);
	//ReverseList(head);
	Sort(head);
	PrintList(head);
	return 0;
}
