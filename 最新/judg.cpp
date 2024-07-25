#include"judg.h"
#include"stack.h"
//�����ͼ���������޷��ƶ������ж���Ϸʧ��
//���ص�ͼʣ��հ׷�����
int JugeDeafet(int(*p)[9])
{
	int  EmptyNum = 0;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (*(*(p + i) + j) == 0)
				EmptyNum++;
	return  EmptyNum;

}

//�ж����������ͬ�ķ�������һ������������
//���ػ��������������
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
			//�ж���ֱ�����Ƿ��������
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i + 1, j) && GetMap(i + 1, j) == GetMap(i + 2, j) && GetMap(i + 2, j) == GetMap(i + 3, j) && GetMap(i + 3, j) == GetMap(i + 4, j))
			{
				int I = i;  int J = j; //��I,J)Ϊ���������������ʼ����

				while (GetMap(I, J) == GetMap(I + 1, J))//�ԣ�I��J)����Ϊ���������ϣ�����ͨ��ɫ�ķ�����ջ���ȴ�����
				{

					Push(st, I, J);//��������������ջ
					I++;//�Ƶ���һ������
				}

				Push(st, I, J);


			}
			//���Խ��߷����Ƿ��������
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i + 1, j + 1) && GetMap(i + 1, j + 1) == GetMap(i + 2, j + 2) && GetMap(i + 2, j + 2) == GetMap(i + 3, j + 3) && GetMap(i + 3, j + 3) == GetMap(i + 4, j + 4))
			{
				int I = i;  int J = j;//��I,J)Ϊ���������������ʼ����

				while (GetMap(I, J) == GetMap(I + 1, J + 1))//�ԣ�I��J)����Ϊ�������Խ��߷����ϣ�����ͬ��ɫ�ķ�����ջ���ȴ�����
				{
					Push(st, I, J);
					I++;
					J++;//�Ƶ���һ������
				}

				Push(st, I, J);

			}
			//ˮƽ�����Ƿ��������
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i, j + 1) && GetMap(i, j + 1) == GetMap(i, j + 2) && GetMap(i, j + 2) == GetMap(i, j + 3) && GetMap(i, j + 3) == GetMap(i, j + 4))
			{
				int I = i; int J = j; //��I,J)Ϊ���������������ʼ����

				while (GetMap(I, J) == GetMap(I, J + 1))//�ԣ�I��J)����Ϊ����ˮƽ�����ϣ�����ͬ��ɫ�ķ�����ջ���ȴ�����
				{
					Push(st, I, J);
					J++;//�Ƶ���һ������
				}

				Push(st, I, J);

			}
			//���Խ��߷����Ƿ��������
			if (GetMap(i, j) && GetMap(i, j) == GetMap(i + 1, j - 1) && GetMap(i + 1, j - 1) == GetMap(i + 2, j - 2) && GetMap(i + 2, j - 2) == GetMap(i + 3, j - 3) && GetMap(i + 3, j - 3) == GetMap(i + 4, j - 4))
			{
				int I = i; int J = j;//��I,J)Ϊ���������������ʼ����

				while (GetMap(I, J) == GetMap(I + 1, J - 1))//�ԣ�I��J)����Ϊ����ˮƽ�����ϣ�����ͬ��ɫ�ķ�����ջ���ȴ�����
				{

					Push(st, I, J);
					I++;//�Ƶ���һ������
					J--;
				}

				Push(st, I, J);

			}
		}
	}
	//ɾ����k��¼ɾ�����������
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