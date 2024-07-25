#include"back.h"

//±£´æ
void PutMap3(int(*p)[9], int a)
{
	ScoreSave[maptop] = a;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			map3[maptop][i][j] = (*(*(p + i) + j));
	maptop++;
}
//³·»Ø
int BackMap(int(*p)[9])
{
	maptop--;
	if (maptop <= 0)
	{
		maptop++;
		return 1;
	}
	Score = ScoreSave[maptop - 1];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			(*(*(p + i) + j)) = map3[maptop - 1][i][j];
	LoadMap(map);
	Sleep(200);
}