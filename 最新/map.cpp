#include"map.h"

//ȡ��ͼ��ֵ
//�������鷶Χ�Ż�0
//������Χ����map[x][y]��ֵ
int GetMap(int x, int y)
{
	if (x >= 9 || y >= 9 || x < 0 || y < 0)//Խ�緵�� 0
		return 0;
	else
		return map[x][y];
}
//�ı��ͼ��ֵ
void SetMap(int x, int y, int temp)
{
	if (x >= 9 || y >= 9 || x < 0 || y < 0)
		;
	else
		map[x][y] = temp;
}

