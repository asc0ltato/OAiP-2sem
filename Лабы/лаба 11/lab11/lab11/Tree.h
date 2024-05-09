#pragma once
#include <iostream>
#include <iostream>
using namespace std;
struct Tree          //дерево
{
	int key;         //ключ
	int a[2];
	int sum;
	Tree* Left, * Right;
};
Tree* makeTree(Tree* Root);
Tree* list(int, int, int);
Tree* insertElem(Tree* t, int, int, int);
void print(Tree* t, int u);
Tree* delet(Tree* Root);

void insert(Tree* t, int u, ofstream&);

void view(Tree* t);
void view2(Tree* t);
void view3(Tree* t);

bool isBalanced(Tree* balanced);