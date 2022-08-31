#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

//���ϲ�α����㷨
//void LevelOrder(Bitrea T) {
//	InitQueue(Q);//��ʼ����������
//	Bitree p;
//	EnQueue(Q, T);//�����ڵ����
//	while (!IsEmpty(Q)) {//���в�����ѭ��
//		DeQueue(Q, p);//��ͷ������
//		visit(p);//���ʳ��ӽ��
//		if (p->lchild != NULL) {
//			EnQueue(Q, p->lchild);//��������Ϊ�գ������������ڵ����
//		}
//		if (p->rrchild != NULL) {
//			EnQueue(Q, p->rchild);//���������գ������������ڵ����
//		}
//	}
//}
#pragma region

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node {
	ElemType val;//��Ҷ�д��val
	struct node* lchild, * rchild;
}node, * BiTree;

void CreateBitree(BiTree& T) {
	ElemType ch;
	cin >> ch;

	if (ch == '#') {//#�����//д���ch!='#'������ȫΪNULL
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
	cout << BiNode->val << " ";//Ϊʲô����endl
}

void InOrder(BiTree T) {//���������ı�������Ľṹ
	if (T != NULL) {
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

#pragma endregion

//P149.5
//������������ö�������洢�ṹ,���һ���ǵݹ��㷨��������ĸ߶�

queue<node*> q;
stack<node*> s;
//�ǵݹ�
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
		if (front == last) {//Ϊʲô��
			level++;
			last = q.back();//queue.back�������һ��Ԫ�ص�����
		}
		q.pop();
	}
	return level;
}

int main() {
	BiTree T;
	cout << "�������������˳���¸�������ֵ,'#'��ʾû�н��:" << endl;
	CreateBitree(T);
	cout << "���������" << endl;
	InOrder(T);
	cout << endl;
	//cout << "���ĸ߶�Ϊ��" << GetH(T) << endl;
	cout << "���ĸ߶�Ϊ��" << GetHeight(T) << endl;
	cout << endl;
	return 0;
}
