#pragma once

#ifndef _HEAD_H

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define MaxSize 100

typedef struct Node {
	ElemType val;
	Node* lchild, * rchild;
};
typedef Node* BiTree;

void CreateBiTree(BiTree& T);
void InOrder(BiTree T);
void visit(BiTree T);

#endif