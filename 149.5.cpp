#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
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
}node, * BiTree;

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

//P149.5
//假设二叉树采用二叉链表存储结构,设计一个非递归算法求二叉树的高度

queue<node*> q;
stack<node*> s;
//非递归
int GetHeight(BiTree T) {
	if (!T) {
		return 0;
	}
	int level = 0;
	node* front=T ,*last=T;
	q.push(T);
	while (!q.empty()) {
		front = q.front();
		if (front->lchild) {
			q.push(front->lchild);
		}
		if (front->rchild) {
			q.push(front->rchild);
		}
		if (front == last) {//为什么？
			level++;
			last = q.back();//queue.back队列最后一个元素的引用
		}
		q.pop();
	}
	return level;
}

int main() {
	BiTree T;
	cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
	CreateBitree(T);
	cout << "中序遍历：" << endl;
	InOrder(T);
	cout << endl;
	//cout << "树的高度为：" << GetH(T) << endl;
	cout << "树的高度为：" << GetHeight(T) << endl;
	cout << endl;
	return 0;
}
