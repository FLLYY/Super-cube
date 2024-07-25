
#ifndef _FILEOPERATE_H_
#define _FILEOPERATE_H_

#include"game.h"
#include"load.h"

//显示排行榜
extern void printRand();

//存档
extern void Save();

//读档
extern void Load();

//更新排行榜
extern void RandList(double time);


#endif#pragma once
