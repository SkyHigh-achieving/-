#define _CRT_SECURE_NO_WARNINGS
//�Ը������������¶��ϣ������ҵĲ�α����㷨��
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
}node,*BiTree;

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

//�Ը������������¶��ϣ������ҵĲ�α����㷨��

queue<node*> q;//����ǽ��
stack<node*> s;
void LevelOrder(BiTree T) {
	q.push(T);//node*
	while (!q.empty()) {
		node* t=q.front();
		q.pop();
		s.push(t);//��ǳ�ؽ���FILO��FIFO������˳���Ƿ���
		if (t->lchild) {
			q.push(t->lchild);
		}
		if (t->rchild) {
			q.push(t->rchild);
		}
	}
	while (!s.empty()) {
		node* x = s.top();
		s.pop();
		visit(x);
	}
}

int main() {
	BiTree T;
	cout << "�������������˳���¸�������ֵ��'#'��ʾû�н�㣺" << endl;//������ֱ��cin>>T
	CreateBitree(T);
	cout << "������������ " << endl;
	InOrder(T);
	cout << endl;
	cout << "��α����� " << endl;
	LevelOrder(T);
	cout << endl;
	return 0;
}
