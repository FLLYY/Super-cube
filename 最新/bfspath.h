#ifndef _BFSPATH_H_
#define _BFSPATH_H_
#include"game.h"
#include"stack.h"
#include"queue.h"


//bfs·��ѡ��
//����·��Ϊ(xi,yi)->(xe,ye)
extern int MapPath1(int xi, int yi, int xe, int ye);



//��·���Ӷ�����ջ
//quΪ���У�frontΪβָ��
//����ջָ��st
extern Stack* PathPushStack(QuType* qu, int front);


//�ƶ�����
extern void move(Stack* st);

#endif#pragma once

