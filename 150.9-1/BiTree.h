#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#pragma region

#define Maxsize 100
#define Elemtype char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node;
typedef node* Bitree;

void CreateBitree(Bitree & T);

void visit(Bitree T);

void InOrder(Bitree T);

void SwapNode(Bitree & T);


typedef struct node {
	Elemtype val;
	struct node* lchild, * rchild;
}node, * Bitree;