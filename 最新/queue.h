
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include"game.h"

//���в���
typedef struct
{
	Box data[1000];
	int front, rear;

}QuType;

extern void InitQueue(QuType*& q);

//���ٶ���
extern void DestroyQueue(QuType*& q);

//�ж϶����Ƿ�Ϊ��
extern int QueueEmpty(QuType*& q);

//���
extern int EnQueue(QuType* q, Box e);

//����
extern int DeQueue(QuType*& q, Box& e);

//�����Ƕ��в���

#endif#pragma once