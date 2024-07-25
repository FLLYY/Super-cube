#include"map.h"

//取地图的值
//超出数组范围放回0
//正常范围返回map[x][y]的值
int GetMap(int x, int y)
{
	if (x >= 9 || y >= 9 || x < 0 || y < 0)//越界返回 0
		return 0;
	else
		return map[x][y];
}
//改变地图的值
void SetMap(int x, int y, int temp)
{
	if (x >= 9 || y >= 9 || x < 0 || y < 0)
		;
	else
		map[x][y] = temp;
}

