#ifndef _MAPPATH_H_
#define _MAPPATH_H_

#include"game.h"
#include"stack.h"

typedef struct Node
{//节点结构体   
	int f, g, h;
	int row;    //该节点所在行   
	int col;    //该节点所在列   
	int direction;//parent节点要移动的方向就能到达本节点   
	struct Node* parent;
}Node, * Lnode;

typedef struct Stack1
{//OPEN CLOSED 表结构体   
	Node* npoint;
	struct Stack1* next;
}Stack1, * LStack1;

//选取OPEN表上f值最小的节点，返回该节点地址
extern Node* getNodeFromOpen();

//判断节点是否相等，相等，不相等  
extern int Equal(Node* suc, Node* goal);


//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址   
extern Node* BelongInOpen(Node* suc);

//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址  
extern Node* BelongInClosed(Node* suc);


//把节点放入OPEN 或CLOSED 表中  
extern void PutintoOpen(Node* suc);
//把节点放入OPEN 或CLOSED 表中
extern void PutintoClosed(Node* suc);

//得到该图块的H值   
extern int getH(int row, int col);

//检测该图块是否可通行   
extern int isCanMove(int col, int row);

//判断（row,col）是否在OPenbian中；
//是就返回open表中该节点
//不在返回NULL
extern Node* checkOpen(int row, int col);

//判断（row,col)是否在Closed表中，在返回1，不在返回0
extern int isInClose(int row, int col);

//生成子节点
extern void creatSeccessionNode(Node* bestNode, int row, int col);


extern void seachSeccessionNode(Node* bestNode);

//a*算法寻路过程
extern int getPath(int StartY, int startX, int destinationY, int destinationX);

//移动操作
extern void Move(Stack* st);

//bfs路线选择
//搜索路径为(xi,yi)->(xe,ye)
//int mappath1(int xi, int yi, int xe, int ye);


#endif#pragma once
