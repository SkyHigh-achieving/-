#include<iostream>
#include<stack>
using namespace std;

#pragma region


#define Maxsize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)
//树的结点
typedef struct LNode {
	ElemType val;
	struct LNode* lchild, * rchild;
}LNode, * Bitree;

//要改变指针，C++可以先把指针的引用传进来
void CreateBitree(Bitree& T) {
	ElemType ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new LNode;
		T->val = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}

void visit(LNode* BiNode) {
	cout << BiNode->val << " ";
}

void InOrder(Bitree T) {
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}


#pragma endregion

//149.3
//编写一个后续遍历二叉树的非递归算法

stack<LNode*> s;

void PostOrder(Bitree T) {
	Bitree p = T, r = NULL;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->lchild;
		}
		else {
			p = s.top();
			if (p->rchild && p->rchild != r) {
				p = p->rchild;
			}
			else {
				s.pop();
				visit(p);
				r = p;
				p = NULL;
			}
		}
	}
}


int main() {
	Bitree T;
	cout << "请输入先序遍历顺序下各种结点的值，'#'表示没有结点" << endl;
	//input:
	CreateBitree(T);
	cout << "中序遍历" << endl;
	InOrder(T);
	cout << endl;
	cout << "非递归后续遍历" << endl;
	PostOrder(T);
	cout << endl;
	return 0;
}