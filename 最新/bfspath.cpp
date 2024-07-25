#include"bfspath.h"



//移动操作
void move(Stack* st)
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

		music(musicname[2]);

		LoadMap(map);

		OriginX = TargetX;
		OriginY = TargetY;

		Sleep(100);
		FlushBatchDraw();
	}
	EndBatchDraw();
}


//将路径从队列入栈
//qu为队列，front为尾指针
//返回栈指针st
Stack* PathPushStack(QuType* qu, int front)
{
	Stack* st;
	InitStack(st);
	int k = qu->front, j, ns = 0;
	printf("\n");
	do
	{
		j = k;
		k = qu->data[k].pre;
		Push(st, qu->data[j].i, qu->data[j].j);
	} while (k >= 0);
	return st;
	while (!IsEmpty(st))
	{
		//ns++;
		int x = 0;
		int y = 0;
		Pop(st, x, y);

	}

}


//bfs路线选择
//搜索路径为(xi,yi)->(xe,ye)
int MapPath1(int xi, int yi, int xe, int ye)
{
	int mg[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			mg[i][j] = map[i][j];
		}
	Box e;
	int i, j, di, il, jl;
	QuType* qu;

	qu = (QuType*)malloc(sizeof(QuType));
	qu->front = qu->rear = 0;

	e.i = xi; e.j = yi; e.pre = -1;
	EnQueue(qu, e);
	mg[xi][yi] = -1;
	while (qu->front != qu->rear)
	{
		DeQueue(qu, e);
		i = e.i; j = e.j;
		if (i == xe && j == ye)
		{
			Stack* st = PathPushStack(qu, qu->front);
			move(st);
			DestroyQueue(qu);
			return 1;
		}
		for (di = 0; di < 4; di++)
		{
			switch (di)
			{
			case 0:il = i - 1; jl = j; break;//上方快
			case 1:il = i; jl = j + 1; break;//右方块
			case 2:il = i + 1; jl = j; break;//下方块
			case 3:il = i; jl = j - 1; break;//左方块
			}
			if (mg[il][jl] == 0 && il >= 0 && jl >= 0 && jl < 9 && il < 9)
			{
				mg[il][jl] = -1;//将其赋值-1，避免来回过度搜索
				e.i = il; e.j = jl;
				e.pre = qu->front;//指向上一个节点
				EnQueue(qu, e);//(il,jl)方块入队
			}
		}
	}
	free(qu);//销毁队列释放内存
	return 0;
}



