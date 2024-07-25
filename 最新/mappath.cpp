
#include"mappath.h"

//ѡȡOPEN����fֵ��С�Ľڵ㣬���ظýڵ��ַ
int destinationRow;     //Ŀ��������   
int destinationCol;     //Ŀ��������   
int directionIndex = 0;

LStack1 Open = NULL;      //����Open��
LStack1 Closed = NULL;    //����Closed��

//ѡȡOPEN����fֵ��С�Ľڵ㣬���ظýڵ��ַ
Node* getNodeFromOpen()
{
	LStack1 temp = Open->next, min = Open->next, minp = Open;
	Node* minx;                     //minx��¼open����f��С�Ľڵ�

	if (temp == NULL)      //���Open��Ϊ��
		return NULL;

	while (temp->next != NULL)   //Open��Ϊ����ѭ��
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

//�жϽڵ��Ƿ���� 
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

//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ   
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

//�жϽڵ��Ƿ�����OPEN���CLOSED�����򷵻ؽڵ��ַ�����򷵻ؿյ�ַ  
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

//�ѽڵ����OPEN ��CLOSED ����  
void PutintoOpen(Node* suc)
{
	Stack1* temp;
	temp = (Stack1*)malloc(sizeof(Stack1));
	temp->npoint = suc;

	temp->next = Open->next;
	Open->next = temp;
}
//�ѽڵ����OPEN ��CLOSED ����
void PutintoClosed(Node* suc)
{
	Stack1* temp;
	temp = (Stack1*)malloc(sizeof(Stack1));
	temp->npoint = suc;
	temp->next = Closed->next;
	Closed->next = temp;
}

//�õ���ͼ���Hֵ   
int getH(int row, int col)
{
	return (abs(destinationRow - row) + abs(destinationCol - col));  //������ֵ
}

//����ͼ���Ƿ��ͨ��   
int isCanMove(int col, int row)
{
	if (col < 0 || col >= 9)
		return 0;
	if (row < 0 || row >= 9)
		return 0;
	return map[col][row] == 0;
}

//�жϣ�row,col���Ƿ���OPenbian�У�
//�Ǿͷ���open���иýڵ�
//���ڷ���NULL
Node* checkOpen(int row, int col)
{
	LStack1 temp = Open->next;
	if (temp == NULL)                                    //���Open��Ϊ��
		return NULL;
	while (temp != NULL)
	{
		if ((temp->npoint->row == row) && (temp->npoint->col == col))  //�����row,col)��Open����,���ظýڵ�
		{
			return temp->npoint;
		}
		else
		{
			temp = temp->next;                          //�ƶ��ڵ��ƶ�
		}
	}
	return NULL;
}

//�жϣ�row,col)�Ƿ���Closed���У��ڷ���1�����ڷ���0
int isInClose(int row, int col)
{
	LStack1 temp = Closed->next;
	if (temp == NULL)                                   //���Closed��Ϊ��
		return 0;
	while (temp != NULL)
	{
		if ((temp->npoint->row == row) && (temp->npoint->col == col))  //���Closed�����и�Ԫ��
		{
			return 1;
		}
		else
		{
			temp = temp->next;                          //Ѱ����һ���ڵ�
		}
	}
	return 0;
}

//�����ӽڵ�
void creatSeccessionNode(Node* bestNode, int row, int col)
{
	int g = bestNode->g + 1;                            //����gֵ

	if (!isInClose(row, col))                           //�����row,col)������Closed����
	{
		Node* oldNode = NULL;

		if ((oldNode = checkOpen(row, col)) != NULL)    //�����row,col)��OPen����
		{
			if (oldNode->g < g)
			{
				oldNode->parent = bestNode;             //���õ�ĸ��׽ڵ����Ϊbestnode�ڵ�
				oldNode->g = g;                         //����gֵ
				oldNode->f = g + oldNode->h;            //����fֵ
			}
		}
		else                                            //����Open������õ����Open��
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
 * ���ݴ���Ľڵ������ӽڵ�
 * @param bestNode
 * @param destinationRow
 * @param destinationCol
 */
void seachSeccessionNode(Node* bestNode)
{
	int row, col;

	//�ϲ��ڵ�   
	if (isCanMove(row = bestNode->row - 1, col = bestNode->col))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	//�²��ڵ�   
	if (isCanMove(row = bestNode->row + 1, col = bestNode->col))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	//�󲿽ڵ�   
	if (isCanMove(row = bestNode->row, col = bestNode->col - 1))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	//�Ҳ��ڵ�   
	if (isCanMove(row = bestNode->row, col = bestNode->col + 1))
	{
		creatSeccessionNode(bestNode, row, col);
	}
	PutintoClosed(bestNode);                           //���ҵ������ŵ����Closed����
}

//a*�㷨Ѱ·����
int getPath(int StartY, int startX, int destinationY, int destinationX)
{

	Open = (Stack1*)malloc(sizeof(Stack1));            //ΪA*Ѱ·����Open�б�
	Open->next = NULL;
	Closed = (Stack1*)malloc(sizeof(Stack1));          //ΪA*Ѱ·����Closed�б�
	Closed->next = NULL;
	Stack* st;                                         //����ջ������㵽Ŀ����·����
	InitStack(st);                                     //��ʼ��ջ

	Node* startNode = (Node*)malloc(sizeof(Node));
	Node* bestNode = NULL;                             //�����Open�����ҳ�f��С�ĵ�
	int index = 0;
	destinationRow = destinationY;
	destinationCol = destinationX;

	//����ʼ��浽Open����
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
		bestNode = getNodeFromOpen();                    //��OPEN����ȡ��fֵ��С�Ľڵ�   
		if (bestNode == NULL)                            //δ�ҵ�·��   
		{
			free(Open);
			free(Closed);
			return 0;
		}
		else if (bestNode->row == destinationRow && bestNode->col == destinationCol) //�ҵ��յ�
		{
			Node* _Node = bestNode;
			while (_Node->parent != NULL)               //���ø��ڵ���Դ�ҵ�·����ջ
			{
				Push(st, _Node->row, _Node->col);
				_Node = _Node->parent;
			}
			Push(st, StartY, startX);

			Move(st);                                   //����ջ�е�Ԫ�ؽ����ƶ�

			DestroyStack(st);                           //����ջ  
			free(Open);                                 //����Open��
			free(Closed);                               //����Closed�� 
			return 1;
		}

		seachSeccessionNode(bestNode);                  // ���ݴ���Ľڵ������ӽڵ�
	}

}

//�ƶ�����
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
