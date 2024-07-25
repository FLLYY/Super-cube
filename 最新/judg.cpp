#include"judg.h"
#include"stack.h"
//如果地图被填满，无法移动，则判定游戏失败
//返回地图剩余空白方格数
int JugeDeafet(int(*p)[9])
{
	int  EmptyNum = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (*(*(p + i) + j) == 0)
				EmptyNum++;
	return  EmptyNum;

}

//判断有无五个相同的方块连在一起，若有则消除
//返回回消除方块的数量
int  JudgeWin()
{
	int i = 0;
	int j = 0;
	Stack* st;
	int k = 0;

	InitStack(st);

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			//判断竖直方向是否可以消除
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i + 1, j) && GetMap(i + 1, j) == GetMap(i + 2, j) && GetMap(i + 2, j) == GetMap(i + 3, j) && GetMap(i + 3, j) == GetMap(i + 4, j))
			{
				int I = i;  int J = j; //（I,J)为待消除方块组的起始方块

				while (GetMap(I, J) == GetMap(I + 1, J))//以（I，J)方块为起点的竖线上，将相通颜色的方块入栈，等待消除
				{

					Push(st, I, J);//将待消除方块入栈
					I++;//推到下一个方块
				}

				Push(st, I, J);


			}
			//正对角线方向是否可以消除
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i + 1, j + 1) && GetMap(i + 1, j + 1) == GetMap(i + 2, j + 2) && GetMap(i + 2, j + 2) == GetMap(i + 3, j + 3) && GetMap(i + 3, j + 3) == GetMap(i + 4, j + 4))
			{
				int I = i;  int J = j;//（I,J)为待消除方块组的起始方块

				while (GetMap(I, J) == GetMap(I + 1, J + 1))//以（I，J)方块为起点的正对角线方向上，将相同颜色的方块入栈，等待消除
				{
					Push(st, I, J);
					I++;
					J++;//推到下一个方块
				}

				Push(st, I, J);

			}
			//水平方向是否可以消除
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i, j + 1) && GetMap(i, j + 1) == GetMap(i, j + 2) && GetMap(i, j + 2) == GetMap(i, j + 3) && GetMap(i, j + 3) == GetMap(i, j + 4))
			{
				int I = i; int J = j; //（I,J)为待消除方块组的起始方块

				while (GetMap(I, J) == GetMap(I, J + 1))//以（I，J)方块为起点的水平方向上，将相同颜色的方块入栈，等待消除
				{
					Push(st, I, J);
					J++;//推到下一个方块
				}

				Push(st, I, J);

			}
			//反对角线方向是否可以消除
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i + 1, j - 1) && GetMap(i + 1, j - 1) == GetMap(i + 2, j - 2) && GetMap(i + 2, j - 2) == GetMap(i + 3, j - 3) && GetMap(i + 3, j - 3) == GetMap(i + 4, j - 4))
			{
				int I = i; int J = j;//（I,J)为待消除方块组的起始方块

				while (GetMap(I, J) == GetMap(I + 1, J - 1))//以（I，J)方块为起点的水平方向上，将相同颜色的方块入栈，等待消除
				{

					Push(st, I, J);
					I++;//推到下一个方块
					J--;
				}

				Push(st, I, J);

			}
		}
	}
	//删除，k记录删除方块的数量
	while (!IsEmpty(st))
	{
		Pop(st, i, j);

		if (GetMap(i, j))
		{
			SetMap(i, j, 0);
			k++;
		}

	}
	DestroyStack(st);

	return k;

}