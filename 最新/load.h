
#ifndef _LOAD_H_
#define _LOAD_H_
#define  _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<stdio.h>
#include<time.h>
#include"game.h"

//加载资源
extern void LoadResource();

//加载地图ing
extern void LoadMap(int(*p)[9]);

//胜利界面
void Win(clock_t start, clock_t stop);


#endif#pragma once