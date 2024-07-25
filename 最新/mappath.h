#ifndef _MAPPATH_H_
#define _MAPPATH_H_

#include"game.h"
#include"stack.h"

typedef struct Node
{//�ڵ�ṹ��   
	int f, g, h;
	int row;    //�ýڵ�������   
	int col;    //�ýڵ�������   
	int direction;//parent�ڵ�Ҫ�ƶ��ķ�����ܵ��ﱾ�ڵ�   
	struct Node* parent;
}Node, * Lnode;

typedef struct Stack1
{//OPEN CLOSED ��ṹ��   
	Node* npoint;
	struct Stack1* next;
}Stack1, * LStack1;

//ѡȡOPEN����fֵ��С�Ľڵ㣬���ظýڵ��ַ
extern Node* getNodeFromOpen();

//�жϽڵ��Ƿ���ȣ���ȣ������  
extern int Equal(Node* suc, Node* goal);


//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ   
extern Node* BelongInOpen(Node* suc);

//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ  
extern Node* BelongInClosed(Node* suc);


//�ѽڵ����OPEN ��CLOSED ����  
extern void PutintoOpen(Node* suc);
//�ѽڵ����OPEN ��CLOSED ����
extern void PutintoClosed(Node* suc);

//�õ���ͼ���Hֵ   
extern int getH(int row, int col);

//����ͼ���Ƿ��ͨ��   
extern int isCanMove(int col, int row);

//�жϣ�row,col���Ƿ���OPenbian�У�
//�Ǿͷ���open���иýڵ�
//���ڷ���NULL
extern Node* checkOpen(int row, int col);

//�жϣ�row,col)�Ƿ���Closed���У��ڷ���1�����ڷ���0
extern int isInClose(int row, int col);

//�����ӽڵ�
extern void creatSeccessionNode(Node* bestNode, int row, int col);


extern void seachSeccessionNode(Node* bestNode);

//a*�㷨Ѱ·����
extern int getPath(int StartY, int startX, int destinationY, int destinationX);

//�ƶ�����
extern void Move(Stack* st);

//bfs·��ѡ��
//����·��Ϊ(xi,yi)->(xe,ye)
//int mappath1(int xi, int yi, int xe, int ye);


#endif#pragma once
