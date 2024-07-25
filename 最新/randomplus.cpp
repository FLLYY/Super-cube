#include"randomplus.h"

void RandomPlus(int(*p)[9], int DeleteNum, int EmptyNum)
{
	srand(time(NULL));

	if (!DeleteNum)                                  
	{//如果上一步没有消除方块，就随机生成三个方块
		int temp = 0;//记录生成方块的数量
		while (temp != 3 && temp != EmptyNum)
		{
			Box b;

			b.i = rand() % 9;//随机生成方块位置
			b.j = rand() % 9;

			if (*(*(p + b.i) + b.j) == 0)//如果该位置没有方块
			{
				*(*(p + b.i) + b.j) = rand() % 7 + 1;//随机生成方块颜色

				temp++;//生成方块数加1
			}
		}
	}
}
