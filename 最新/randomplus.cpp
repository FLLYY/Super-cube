#include"randomplus.h"

void RandomPlus(int(*p)[9], int DeleteNum, int EmptyNum)
{
	srand(time(NULL));

	if (!DeleteNum)                                  
	{//�����һ��û���������飬�����������������
		int temp = 0;//��¼���ɷ��������
		while (temp != 3 && temp != EmptyNum)
		{
			Box b;

			b.i = rand() % 9;//������ɷ���λ��
			b.j = rand() % 9;

			if (*(*(p + b.i) + b.j) == 0)//�����λ��û�з���
			{
				*(*(p + b.i) + b.j) = rand() % 7 + 1;//������ɷ�����ɫ

				temp++;//���ɷ�������1
			}
		}
	}
}
