#include "music.h"


//“Ù¿÷≤•∑≈
void music(char *str)
{
	char close[20] = "close ";
	char open[20] = "open ";
	char play[20] = "play ";

	if (*str == '2')
		strcpy(play, "play 2.mp3 repeat");
	else
		strcat(play, str);

	strcat(close, str);
	strcat(open, str);
	
	mciSendString(close, 0, 0, 0);
	mciSendString(open, 0, 0, 0);
	mciSendString(play, 0, 0, 0);
}
