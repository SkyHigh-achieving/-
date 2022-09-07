
#include"BiTree.h"


void CreateBitree(Bitree& T) {
	Elemtype ch;
	cin >> ch;

	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new node;
		T->val = ch;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}

void visit(Bitree T) {
	cout << T->val << " ";
}

void InOrder(Bitree T) {
	if (T) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

