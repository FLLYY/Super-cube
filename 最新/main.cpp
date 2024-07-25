#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include"path.h"
int imgIndex[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 }; //用于读取文件
IMAGE img[15];//定义图片变量
char musicname[9][10] = { "1.mp3","2.mp3","3.mp3","4.mp3","5.mp3","6.mp3","7.mp3","8.mp3","9.mp3" };//定义音乐变量名
int Score;//定义分数
int map3[50][9][9]; //用来保存每次移动后地图的数组
int map[9][9] = { 0 };  //地图
int ScoreSave[50] = { 0 }; //用来保存每次移动后的分数
int maptop = 0;        //指向map3,ScoreSave中的待保存位置
clock_t start, stop,mousestart,mousestop,otherstart,otherstop;   //保存开始和结束的时间
double time_;
Box a;       //定义储存起点位置的坐标
Box c;      //定义储存终点位置的坐标
double OldTime=0 ;
int degree;
int s1 = 1;

int main()
{
	srand(time(NULL));

	initgraph(672, 485);
	LoadResource();
next0:
	putimage(0, 0, &img[10]);
	
	if (!Start_())
	{
		RandomPlus(map, 0, 3);
		RandomPlus(map, 0, 3);
	}

	//进入游戏
	while (1)
	{
		PutMap3(map, Score);//保存地图和分数


		BeginBatchDraw();
		LoadMap(map);//加载地图
		EndBatchDraw();

		if (!JugeDeafet(map))  //如果空白方块为0   ,游戏结束
		{
			memset(map, 0, sizeof(map));//初始化地图
			music(musicname[5]);
			putimage(220, 180, &img[8]);
			Sleep(2000);
			FlushBatchDraw();
			MOUSEMSG mouse;
			while (1)
			{
				mouse = GetMouseMsg();
				if (mouse.x >= 25 && mouse.x <= 75 && mouse.y >= 427 && mouse.y <= 450 && mouse.uMsg == WM_LBUTTONDOWN)
				{
					break;
				}

			}
			goto next0;
		}

	ReGetMouse:if (GetMouse() == -1)  //如果点击退出游戏
		goto next0;
	if (!Path(c.i, c.j, a.i, a.j))   //如果移动失败，重新选择移动位置
		goto ReGetMouse;

	int DeleteNum = JudgeWin();
	//检测是否可以消除并且消除连续物块,DeleteNum记录消除方块的数量
	if (DeleteNum)
	{
		music(musicname[3]);
		Score += DeleteNum * 10;
	}
	// 如果胜利
	if (Score >= 500)
	{
		stop = clock();   //得到结束时间
		Win(start, stop);
		goto next0; //重新跳入菜单

	}

	RandomPlus(map, DeleteNum, JugeDeafet(map));//随机点  生成随机颜色

	DeleteNum = JudgeWin();

	if (DeleteNum)
	{
		Score += DeleteNum * 10;
	}

	}
	_getch();
	closegraph();
}
