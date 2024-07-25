#include"fileoperate.h"


int cmp_double(const void* e1, const void* e2)
{
	return *(double*)e1 == *(double*)e2 ? 0 : *(double*)e1 > *(double*)e2 ? 1 : -1;
}
//存档
void Save()
{
	settextstyle(75, 0, "STCAIYUN");
	outtextxy(100, 100, "保存成功！！");
	Sleep(300);
	FILE* p;
	p = fopen("cundang.txt", "w+");

	stop = clock();
	double TemTime = (double)(stop - start) / CLK_TCK;//结束计时
	TemTime += OldTime;
	fprintf(p, "%lf\n", TemTime);
	fprintf(p, "%d\n", Score);
	fprintf(p, "%d\n", degree);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fprintf(p, "%d ", map[i][j]);
		}
		fprintf(p, "\n");
	}

	fclose(p);
}

//读档
void Load()
{
	FILE* fp = fopen("cundang.txt", "r+");

	fscanf(fp, "%lf", &OldTime);

	fscanf(fp, "%d", &Score);
	fscanf(fp, "%d", &degree);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fscanf(fp, "%d ", &map[i][j]);

		}
	}
	LoadMap(map);
	fclose(fp);
}


//更新排行榜
void RandList(double time)
{
	char arc1[14];
	if (degree == 6)
		strcpy(arc1, "cundang1.txt");
	else if (degree == 4)
		strcpy(arc1, "cundang2.txt");
	else if (degree == 2)
		strcpy(arc1, "cundang3.txt");
		FILE* fp = fopen(arc1,"r");
		double rank[100] = { 0 };
		int i = 0;
		while (fscanf(fp, "%lf", &rank[i]) != EOF && i <= 9)
			i++;
		int p = i;
		rank[i] = time;
		qsort(rank, i + 1, sizeof(double), cmp_double);
		fclose(fp);
		FILE* f = fopen(arc1, "w");
		for (int i = 0; i <= p; i++)
			fprintf(f, "%lf\n", rank[i]);
		fclose(f);
}

//打印排行榜
void printRand()
{
	FILE* fp1 = fopen("cundang1.txt", "r");
	double rank1[100] = { 0 };
	int i = 0;
	while (fscanf(fp1, "%lf", &rank1[i]) != EOF && i <= 9)
		i++;
	fclose(fp1);

	FILE* fp2 = fopen("cundang2.txt", "r");
	double rank2[100] = { 0 };
	int j = 0;
	while (fscanf(fp2, "%lf", &rank2[j]) != EOF && j <= 9)
		j++;
	fclose(fp2);

	FILE* fp3 = fopen("cundang3.txt", "r");
	double rank3[100] = { 0 };
	int k = 0;
	while (fscanf(fp3, "%lf", &rank3[k]) != EOF && k <= 9)
		k++;
	fclose(fp3);

	settextstyle(25, 0, "STCAIYUN");
	setbkmode(TRANSPARENT);
	outtextxy(230, 95, "<排行榜>");
	outtextxy(134 + 70, 122, "简单");
	outtextxy(134 + 140, 122, "困难");
	outtextxy(134 + 210, 122, "炼狱");
	for (int j = 0; j < i; j++)
	{
		char str1[20] = "";
		char str2[20] = "";
		char str3[20] = "";
		char aaa[4] = "";
		sprintf(str1, "%.1lf", rank1[j]);
		sprintf(str2, "%.1lf", rank2[j]);
		sprintf(str3, "%.1lf", rank3[j]);
		sprintf(aaa, "%d", j + 1);
		settextcolor(WHITE);
		settextstyle(25, 0, "AdobeHeitiStd-Regular");
		outtextxy(134, j * 25 + 135 + 15, "NO.");
		outtextxy(134 + 35, j * 25 + 135 + 15, aaa);
		outtextxy(134 + 70, j * 25 + 135 + 15, str1);
		outtextxy(134 + 140, j * 25 + 135 + 15, str2);
		outtextxy(134 + 210, j * 25 + 135 + 15, str3);
	}
}