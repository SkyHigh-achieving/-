
#include"BiTree.h"
stack<node*> s;
queue<node*> q;


//P150.9
//����B��һ�ò�����ʽ�ṹ�洢�Ķ�����, ��дһ������B�����н�������������
//�н����ĺ���

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
	cout<< "�������������˳���¸�������ֵ,'#'��ʾû�н��:" << endl;
	CreateBitree(T);
	cout << "InOrder" << endl;
	InOrder(T);
	cout<<endl;
	SwapNode(T);
	InOrder(T);
	cout << endl;
	return 0;
}
