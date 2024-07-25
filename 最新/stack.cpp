#include"stack.h"

int IsEmpty(Stack* S)
{
	return (S->top == -1 ? 1 : 0);
}

//��ʼ��ջ
void InitStack(Stack*& s)
{
	s = (Stack*)malloc(sizeof(Stack));
	s->top = -1;
}

//����ջ
void DestroyStack(Stack*& s)
{
	free(s);
}

//��ջ
int Push(Stack* S, int x, int y)
{
	S->top++;
	S->MoveData[S->top].i = x;
	S->MoveData[S->top].j = y;
	return 1;
}

//��ջ
int Pop(Stack* S, int& x, int& y)
{
	x = S->MoveData[S->top].i;
	y = S->MoveData[S->top].j;
	S->top--;
	return 1;
}