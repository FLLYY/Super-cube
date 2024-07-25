#include"load.h"

//加载资源
void  LoadResource()
{
	for (int i = 0; i < 15; i++)
	{
		char fileName[20] = "";
		sprintf(fileName, "%d.png", imgIndex[i]);
		loadimage(img + i, fileName);
	}
	putimage(0, 0, &img[10]);
	
	music(musicname[0]);
	music(musicname[1]);
}
//加载地图ing
void LoadMap(int(*p)[9])
{
	putimage(0, 0, &img[0]);
	settextstyle(50, 0, "STXINGKA");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);//透明
	char StrScore[20] = "";
	sprintf(StrScore, "%d", Score);
	outtextxy(527, 112, StrScore);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int x = 45 * j;
			int y = 45 * i;
			switch (*(*(p + i) + j))
			{
			case 1:putimage(x + 99, y + 43, &img[1]); break;
			case 2:putimage(x + 99, y + 43, &img[2]); break;
			case 3:putimage(x + 99, y + 43, &img[3]); break;
			case 4:putimage(x + 99, y + 43, &img[4]); break;
			case 5:putimage(x + 99, y + 43, &img[5]); break;
			case 6:putimage(x + 99, y + 43, &img[6]); break;
			case 7:putimage(x + 99, y + 43, &img[7]); break;
			}
		}
	}
	stop = clock();
	double TemTime = (double)(stop - start) / CLK_TCK;//结束计时
	TemTime += OldTime;
	char str[20] = "";
	settextcolor(WHITE);
	sprintf(str, "%lf", TemTime);
	settextstyle(25, 0, "AdobeHeitiStd-Regular");
	outtextxy(511, 318, "已耗时");
	outtextxy(511, 347, str);
}

//胜利界面
void Win(clock_t start, clock_t stop)
{
	BeginBatchDraw();
	LoadMap(map);    //加载地图

	stop = clock();   //得到结束时间
	double time_ = OldTime + (double)(stop - start) / CLK_TCK;//结束计时

	char str[20] = "";
	settextcolor(WHITE);
	sprintf(str, "%lf", time_);

	music(musicname[4]);

	putimage(150, 80, &img[13], SRCAND);
	putimage(150, 80, &img[12], SRCPAINT);

	EndBatchDraw();

	RandList(time_);  //将所用时间加入排行榜
	memset(map, 0, sizeof(map));          //初始化地图

	Score = 0;
	MOUSEMSG mouse;
	while (1)
	{
		mouse = GetMouseMsg();
		if (mouse.x >= 25 && mouse.x <= 75 && mouse.y >= 427 && mouse.y <= 450 && mouse.uMsg == WM_LBUTTONDOWN)
		{
			break;
		}

	}
}