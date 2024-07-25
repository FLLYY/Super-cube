
#include"mappath.h"

//选取OPEN表上f值最小的节点，返回该节点地址
int destinationRow;     //目标所在行   
int destinationCol;     //目标所在列   
int directionIndex = 0;

LStack1 Open = NULL;      //开辟Open表
LStack1 Closed = NULL;    //开辟Closed表

//选取OPEN表上f值最小的节点，返回该节点地址
Node* getNodeFromOpen()
{
	LStack1 temp = Open->next, min = Open->next, minp = Open;
	Node* minx;                     //minx记录open表中f最小的节点

	if (temp == NULL)      //如果Open表为空
		return NULL;

	while (temp->next != NULL)   //Open表不为空则循环
	{
		if ((temp->next->npoint->f) < (min->npoint->f))
		{
			min = temp->next;
			minp = temp;
		}
		temp = temp->next;
	}
	minx = min->npoint;
	temp = minp->next;
	minp->next = minp->next->next;
	free(temp);
	return minx;
}

//判断节点是否相等 
int Equal(Node* suc, Node* goal)
{
	if ((suc->row == goal->row) && (suc->col == goal->col))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址   
Node* BelongInOpen(Node* suc)
{
	LStack1 temp = Open->next;
	if (temp == NULL)
		return NULL;
	while (temp != NULL)
	{
		if (Equal(suc, temp->npoint))
		{
			return temp->npoint;
		}
		else
		{
			temp = temp->next;
		}
	}
	return NULL;
}

//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址  
Node* BelongInClosed(Node* suc)
{
	LStack1 temp = Closed->next;
	if (temp == NULL)
		return NULL;
	while (temp != NULL)
	{
		if (Equal(suc, temp->npoint))
		{
			return temp->npoint;
		}
		else
		{
			temp = temp->next;
		}
	}
	return NULL;
}

//把节点放入OPEN 或CLOSED 表中  
void PutintoOpen(Node* suc)
{
	Stack1* temp;
	temp = (Stack1*)malloc(sizeof(Stack1));
	temp->npoint = suc;

	temp->next = Open->next;
	Open->next = temp;
}
//把节点放入OPEN 或CLOSED 表中
void PutintoClosed(Node* suc)
{
	Stack1* temp;
	temp = (Stack1*)malloc(sizeof(Stack1));
	temp->npoint = suc;
	temp->next = Closed->next;
	Closed->next = temp;
}

//得到该图块的H值   
int getH(int row, int col)
{
	return (abs(destinationRow - row) + abs(destinationCol - col));  //曼哈顿值
}

//检测该图块是否可通行   
int isCanMove(int col, int row)
{
	if (col < 0 || col >= 9)
		return 0;
	if (row < 0 || row >= 9)
		return 0;
	return map[col][row] == 0;
}

//判断（row,col）是否在OPenbian中；
//是就返回open表中该节点
//不在返回NULL
Node* checkOpen(int row, int col)
{
	LStack1 temp = Open->next;
	if (temp == NULL)                                    //如果Open表为空
		return NULL;
	while (temp != NULL)
	{
		if ((temp->npoint->row == row) && (temp->npoint->col == col))  //如果（row,col)在Open表中,返回该节点
		{
			return temp->npoint;
		}
		else
		{
			temp = temp->next;                          //推动节点移动
		}
	}
	return NULL;
}

//判断（row,col)是否在Closed表中，在返回1，不在返回0
int isInClose(int row, int col)
{
	LStack1 temp = Closed->next;
	if (temp == NULL)                                   //如果Closed表为空
		return 0;
	while (temp != NULL)
	{
		if ((temp->npoint->row == row) && (temp->npoint->col == col))  //如果Closed表中有该元素
		{
			return 1;
		}
		else
		{
			temp = temp->next;                          //寻找下一个节点
		}
	}
	return 0;
}

//生成子节点
void creatSeccessionNode(Node* bestNode, int row, int col)
{
	int g = bestNode->g + 1;                            //更新g值

	if (!isInClose(row, col))                           //如果（row,col)不在在Closed表中
	{
		Node* oldNode = NULL;

		if ((oldNode = checkOpen(row, col)) != NULL)    //如果（row,col)在OPen表中
		{
			if (oldNode->g < g)
			{
				oldNode->parent = bestNode;             //将该点的父亲节点更新为bestnode节点
				oldNode->g = g;                         //更新g值
				oldNode->f = g + oldNode->h;            //更新f值
			}
		}
		else                                            //不在Open表里，将该点存入Open表
		{
			Node* node = (Node*)malloc(sizeof(Node));
			node->parent = bestNode;
			node->g = g;
			node->h = getH(row, col);
			node->f = node->g + node->h;
			node->row = row;
			node->col = col;
			directionIndex++;
			node->direction = directionIndex;
			PutintoOpen(node);
		}
	}
}

/**
 * 根据传入的节点生成子节点
 * @param bestNode
 * @param destinationRow
 * @param destinationCol
 */
void seachSeccessionNode(Node* bestNode)
{
	int row, col;

	//上部节点   
	if (isCanMove(row = bestNode->row - 1, col = bestNode->col))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	//下部节点   
	if (isCanMove(row = bestNode->row + 1, col = bestNode->col))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	//左部节点   
	if (isCanMove(row = bestNode->row, col = bestNode->col - 1))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	//右部节点   
	if (isCanMove(row = bestNode->row, col = bestNode->col + 1))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	PutintoClosed(bestNode);                           //将找到了最优点放入Closed表中
}

//a*算法寻路过程
int getPath(int StartY, int startX, int destinationY, int destinationX)
{

	Open = (Stack1*)malloc(sizeof(Stack1));            //为A*寻路开辟Open列表
	Open->next = NULL;
	Closed = (Stack1*)malloc(sizeof(Stack1));          //为A*寻路开辟Closed列表
	Closed->next = NULL;
	Stack* st;                                         //开辟栈保存起点到目标点的路径点
	InitStack(st);                                     //初始化栈

	Node* startNode = (Node*)malloc(sizeof(Node));
	Node* bestNode = NULL;                             //保存从Open表中找出f最小的点
	int index = 0;
	destinationRow = destinationY;
	destinationCol = destinationX;

	//将起始点存到Open表中
	startNode->parent = NULL;
	startNode->row = StartY;
	startNode->col = startX;
	startNode->g = 0;
	startNode->h = getH(startNode->row, startNode->col);
	startNode->f = startNode->g + startNode->h;
	startNode->direction = 0;
	PutintoOpen(startNode);

	while (1)
	{
		bestNode = getNodeFromOpen();                    //从OPEN表中取出f值最小的节点   
		if (bestNode == NULL)                            //未找到路径   
		{
			free(Open);
			free(Closed);
			return 0;
		}
		else if (bestNode->row == destinationRow && bestNode->col == destinationCol) //找到终点
		{
			Node* _Node = bestNode;
			while (_Node->parent != NULL)               //利用父节点溯源找到路径入栈
			{
				Push(st, _Node->row, _Node->col);
				_Node = _Node->parent;
			}
			Push(st, StartY, startX);

			Move(st);                                   //利用栈中的元素进行移动

			DestroyStack(st);                           //销毁栈  
			free(Open);                                 //销毁Open表
			free(Closed);                               //销毁Closed表 
			return 1;
		}

		seachSeccessionNode(bestNode);                  // 根据传入的节点生成子节点
	}

}

//移动操作
void Move(Stack* st)
{
	BeginBatchDraw();

	int OriginX = 0, OriginY = 0;
	int TargetX = 0, TargetY = 0;

	Pop(st, OriginX, OriginY);

	while (!IsEmpty(st))
	{
		Pop(st, TargetX, TargetY);

		map[TargetX][TargetY] = map[OriginX][OriginY];
		map[OriginX][OriginY] = 0;

		LoadMap(map);

		OriginX = TargetX;
		OriginY = TargetY;

		Sleep(100);
		FlushBatchDraw();
	}
	EndBatchDraw();
}
