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
//��֪�������Զ�������洢, ��д�㷨���:��������ÿ��Ԫ��ֵΪx�Ľ��, ɾȥ��
//��Ϊ��������, ���ͷ���Ӧ�Ŀռ�

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
	cout << "�������������˳���¸�������ֵ��'#'��ʾû�н��" << endl;
	CreateBiTree(T);
	cout << "���������" << endl;
	InOrder(T);
	cout << endl;
	char X = 'D';
	cout << "ɾ��" << X << "���������Ϊ" << endl;
	DeleteX(T,X);
	InOrder(T);
	cout << endl;
	return 0;
}