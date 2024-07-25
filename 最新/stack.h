#ifndef _STACK_H_
#define _STACK_H_
#include"game.h"
//������������
//ջ�Ĳ�����1��ʵ�ֳ��ع��ܣ�
//2��Ϊ������ƶ�����·����

typedef struct
{
	Box MoveData[1000]; // ���֧��1000���ƶ�
	int top;
}Stack;

//�ж�ջ�Ƿ�Ϊ��
extern int IsEmpty(Stack* S);

//��ʼ��ջ
extern void InitStack(Stack*& s);
//����ջ
extern void DestroyStack(Stack*& s);
//��ջ
extern int Push(Stack* S, int x, int y);
//��ջ
extern int Pop(Stack* S, int& x, int& y);




#endif#pragma once