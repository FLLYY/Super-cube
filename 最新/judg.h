#ifndef _JUDG_H_
#define _JUDG_H_
#include"game.h"

//判断有无五个相同的方块连在一起，若有则消除
//返回回消除方块的数量
extern int  JudgeWin();

//如果地图被填满，无法移动，则判定游戏失败
//返回地图剩余空白方格数
extern int JugeDeafet(int(*p)[9]);
#endif#pragma once
