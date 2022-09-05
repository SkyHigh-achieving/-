
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#pragma region
using namespace std;


#define ElemType char
#define MaxSize 100
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node {
	ElemType val;
	node* lchild, * rchild;
}node,*BiTree;

void CreateTree(BiTree& T) {
	ElemType ch;

	cin >> ch;
	if (ch == '#') {
		T = NULL;//****
	}
	else {
		T = new node;
		T->val = ch;
		CreateTree(T->lchild);;
		CreateTree(T->rchild);
	}
}

void visit(BiTree T) {
	cout << T->val << " ";
}

void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

#pragma endregion
//P150.7
//二又树按二叉链表形式存储, 写一个判别给定二叉树是否是完全二叉树的算法

stack<node*>s;
queue < node*>q;

bool Judge_ComTrees(BiTree T) {
	q.push(T);
	while (!q.empty()) {
		node* t = q.front();
		q.pop();
		if (t) {
			q.push(t->lchild);
			q.push(t->rchild);
		}
		else {
			while(!q.empty()) {
				node* x = q.front();
				q.pop();
				if (x) {
					return false;
				}
			}
		}
	}
	return true;//对应第一个if
}

int main() {
	BiTree T;
	cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
	CreateTree(T);
	cout << "InOder; " << endl;
	InOrder(T);
	cout << endl;
	cout << "PostOrder: " << endl;
	PostOrder(T);
	cout << endl;
	if (Judge_ComTrees(T)) {
		cout << "IsComTree!" << endl;
	}
	else {
		cout << "Nah!" << endl;
	}
	return 0;
}
