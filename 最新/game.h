
#ifndef _GAME_H_
#define _GAME_H_
#include"load.h"
#include"fileoperate.h"
#include"back.h"
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include"map.h"
#include"judg.h"
#include"randomplus.h"
#include"mouseoperate.h"
#include "music.h"
#include"path.h"





extern int imgIndex[15];
extern IMAGE img[15];
extern char musicname[9][10];
extern int Score;
extern int map[9][9];
extern clock_t start, stop, mousestart, mousestop, otherstart, otherstop;   //保存开始和结束的时间
extern double time_;
extern double OldTime;
extern int degree;
typedef struct
{
	int i;
	int j;
	int pre;
}Box;
extern Box a,c;
extern int maptop;
extern int ScoreSave[50];
extern int map3[50][9][9];


#endif#pragma once