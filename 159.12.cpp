#define _CRT_SECURE_NO_WARNINGS

#include"head.h"
#pragma region
void CreateBiTree(BiTree& T) {
	ElemType ch;
	cin >> ch;

	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new Node;//**
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

#pragma endregion

//P150.12
//在二又树中查找值为x的结点, 试编写算法(用C语言)打印值为x的结点的所有祖
//先, 假设值为x的结点不多于一个。

stack<Node*>s;
 bool FindAncestors(BiTree T,ElemType x){
	 if (!T) {
		 return false;
	 }
	 if (T->val == x) {
		 return true;
	 }
	 if (FindAncestors(T->lchild,x) || FindAncestors(T->rchild,x)) {//需要递归，否则不知道在哪个篮子里
			 s.push(T);
			 return true;
	 }
	 return false;
 }
 void print() {//打印s里面的数组，不需要形参
	 while (!s.empty()) {
		 cout << s.top()->val << " ";
		 s.pop();
	 }
 }

 int main()
 {
	 BiTree T;
	 cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;

	 CreateBiTree(T);
	 cout << "中序遍历：" << endl;
	 InOrder(T);
	 cout << endl;
	 char X = 'I';
	 FindAncestors(T, X);
	 cout << X << "的祖先结点为：" << endl;
	 print();
	 return 0;
 }