
#include"BiTree.h"
stack<node*> s;
queue<node*> q;


//P150.9
//设树B是一棵采用链式结构存储的二叉树, 编写一个把树B中所有结点的左、右子树进
//行交换的函数

void Swap(Bitree& a, Bitree& b) {
	Bitree t = a;
	a = b;
	b = t;
}

void SwapNode(Bitree& T) {
	if (T) {
		SwapNode(T->lchild);
		SwapNode(T->rchild);
		Swap(T->lchild, T->rchild);
	}
}

int main() {
	Bitree T;
	cout<< "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
	CreateBitree(T);
	cout << "InOrder" << endl;
	InOrder(T);
	cout<<endl;
	SwapNode(T);
	InOrder(T);
	cout << endl;
	return 0;
}
