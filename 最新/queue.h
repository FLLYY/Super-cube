
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"game.h"

//队列操作
typedef struct
{
	Box data[1000];
	int front, rear;

}QuType;

extern void InitQueue(QuType*& q);

//销毁队列
extern void DestroyQueue(QuType*& q);

//判断队列是否为空
extern int QueueEmpty(QuType*& q);

//入队
extern int EnQueue(QuType* q, Box e);

//出队
extern int DeQueue(QuType*& q, Box& e);

//以上是队列操作

#endif#pragma once