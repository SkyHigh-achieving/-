#define _CRT_SECURE_NO_WARNINGS
#include"head.h"

void CreateBiTree(BiTree& T) {
	ElemType ch;

	cin >> ch;

	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new Node;
		T->val = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void visit(BiTree T) {
	cout << T->val << " ";
}

void InOrder(BiTree T) {
	if (T) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//P150.11
//已知二叉树以二叉链表存储, 编写算法完成:对于树中每个元素值为x的结点, 删去以
//它为根的子树, 并释放相应的空间

queue<Node*> q;
stack<Node*> s;
void DeleteNode(BiTree &T){
	if (T) {
		DeleteNode(T->lchild);
		DeleteNode(T->rchild);
		delete(T);
	}
}

void DeleteX(BiTree& T,ElemType x) {
	q.push(T);
	while (!q.empty()) {
		BiTree p = q.front();
		q.pop();
		if (p->lchild) {
			if (p->lchild->val== x) {
				DeleteNode(p->lchild);
				p->lchild = NULL;
			}
			else {
				q.push(p->lchild);
			}
		}//endif
		if (p->rchild) {
			if (p->rchild->val == x) {
				DeleteNode(p->rchild);
				p->rchild = NULL;
			}
			else {
				q.push(p->rchild);
			}
		}//endif
	}//while
}

int main() {
	BiTree T;
	cout << "请输入先序遍历顺序下各个结点的值，'#'表示没有结点" << endl;
	CreateBiTree(T);
	cout << "中序遍历：" << endl;
	InOrder(T);
	cout << endl;
	char X = 'D';
	cout << "删除" << X << "后中序遍历为" << endl;
	DeleteX(T,X);
	InOrder(T);
	cout << endl;
	return 0;
}