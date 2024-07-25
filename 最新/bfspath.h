#ifndef _BFSPATH_H_
#define _BFSPATH_H_
#include"game.h"
#include"stack.h"
#include"queue.h"


//bfs路线选择
//搜索路径为(xi,yi)->(xe,ye)
extern int MapPath1(int xi, int yi, int xe, int ye);



//将路径从队列入栈
//qu为队列，front为尾指针
//返回栈指针st
extern Stack* PathPushStack(QuType* qu, int front);


//移动操作
extern void move(Stack* st);

#endif#pragma once

