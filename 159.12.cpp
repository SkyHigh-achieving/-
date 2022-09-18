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
//�ڶ������в���ֵΪx�Ľ��, �Ա�д�㷨(��C����)��ӡֵΪx�Ľ���������
//��, ����ֵΪx�Ľ�㲻����һ����

stack<Node*>s;
 bool FindAncestors(BiTree T,ElemType x){
	 if (!T) {
		 return false;
	 }
	 if (T->val == x) {
		 return true;
	 }
	 if (FindAncestors(T->lchild,x) || FindAncestors(T->rchild,x)) {//��Ҫ�ݹ飬����֪�����ĸ�������
			 s.push(T);
			 return true;
	 }
	 return false;
 }
 void print() {//��ӡs��������飬����Ҫ�β�
	 while (!s.empty()) {
		 cout << s.top()->val << " ";
		 s.pop();
	 }
 }

 int main()
 {
	 BiTree T;
	 cout << "�������������˳���¸�������ֵ,'#'��ʾû�н��:" << endl;

	 CreateBiTree(T);
	 cout << "���������" << endl;
	 InOrder(T);
	 cout << endl;
	 char X = 'I';
	 FindAncestors(T, X);
	 cout << X << "�����Ƚ��Ϊ��" << endl;
	 print();
	 return 0;
 }