
#ifndef _LOAD_H_
#define _LOAD_H_
#define  _CRT_SECURE_NO_WARNINGS
#include<graphics.h>
#include<stdio.h>
#include<time.h>
#include"game.h"

//������Դ
extern void LoadResource();

//���ص�ͼing
extern void LoadMap(int(*p)[9]);

//ʤ������
void Win(clock_t start, clock_t stop);


#endif#pragma once