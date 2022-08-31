#define _CRT_SECURE_NO_WARNINGS
//试给出二叉树自下而上，从左到右的层次遍历算法。
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//书上层次遍历算法
//void LevelOrder(Bitrea T) {
//	InitQueue(Q);//初始化辅助队列
//	Bitree p;
//	EnQueue(Q, T);//将根节点入队
//	while (!IsEmpty(Q)) {//队列不空则循环
//		DeQueue(Q, p);//队头结点出队
//		visit(p);//访问出队结点
//		if (p->lchild != NULL) {
//			EnQueue(Q, p->lchild);//左子树不为空，则左子树根节点入队
//		}
//		if (p->rrchild != NULL) {
//			EnQueue(Q, p->rchild);//右子树不空，则右子树根节点入队
//		}
//	}
//}
#pragma region

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node {
	ElemType val;//大家都写成val
	struct node* lchild, * rchild;
}node,*BiTree;

void CreateBitree(BiTree& T) {
	ElemType ch;
	cin >> ch;

	if (ch == '#') {//#代表空//写错成ch!='#'，导致全为NULL
		T = NULL;
	}
	else {
		T = new node;
		T->val = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}

void visit(node* BiNode) {
	cout << BiNode->val << " ";//为什么不能endl
}

void InOrder(BiTree T) {//遍历并不改变这个树的结构
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

#pragma endregion

//试给出二叉树自下而上，从左到右的层次遍历算法。

queue<node*> q;//存的是结点
stack<node*> s;
void LevelOrder(BiTree T) {
	q.push(T);//node*
	while (!q.empty()) {
		node* t=q.front();
		q.pop();
		s.push(t);//粗浅地将，FILO和FIFO出容器顺序是反的
		if (t->lchild) {
			q.push(t->lchild);
		}
		if (t->rchild) {
			q.push(t->rchild);
		}
	}
	while (!s.empty()) {
		node* x = s.top();
		s.pop();
		visit(x);
	}
}

int main() {
	BiTree T;
	cout << "请输入先序遍历顺序下各个结点的值，'#'表示没有结点：" << endl;//不可以直接cin>>T
	CreateBitree(T);
	cout << "中序遍历结果： " << endl;
	InOrder(T);
	cout << endl;
	cout << "层次遍历： " << endl;
	LevelOrder(T);
	cout << endl;
	return 0;
}
