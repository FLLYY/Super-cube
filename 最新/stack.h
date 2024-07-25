#ifndef _STACK_H_
#define _STACK_H_
#include"game.h"
//基本操作函数
//栈的操作，1、实现撤回功能，
//2、为物体的移动保存路径，

typedef struct
{
	Box MoveData[1000]; // 最多支持1000步移动
	int top;
}Stack;

//判断栈是否为空
extern int IsEmpty(Stack* S);

//初始化栈
extern void InitStack(Stack*& s);
//销毁栈
extern void DestroyStack(Stack*& s);
//进栈
extern int Push(Stack* S, int x, int y);
//出栈
extern int Pop(Stack* S, int& x, int& y);




#endif#pragma once