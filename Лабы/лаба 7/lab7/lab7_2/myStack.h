#pragma once
struct Stack
{
	int data;
	Stack* next;
};

void push(Stack*& top, int data);
int pop(Stack*& top);
void print(Stack* top);
void createStack(Stack*& top, int n);
void createStacks(Stack*& top, Stack*& top1, Stack*& top2);
void clear(Stack*& top);
void writeToFile(Stack* top, const char* fileName);
void readFromFile(Stack * &top, const char* fileName);