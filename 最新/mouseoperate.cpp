#include"mouseoperate.h"



int  GetMouse()
{
	int k = 0;
	MOUSEMSG mouse;
	mousestart = clock();

	while (1)
	{

		while (1)
		{

			mousestop = clock();
			double MouseTime = (double)(mousestop - mousestart) / CLK_TCK;//������ʱ
			if (MouseTime >= degree)
			{
				RandomPlus(map, 0, JugeDeafet(map));
				LoadMap(map);
				if (!JugeDeafet(map))  //����հ׷���Ϊ0   ,��Ϸ����
				{
					memset(map, 0, sizeof(map));//��ʼ����ͼ
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
					return -1;
				}
				mousestart = clock();
			}
			if (MouseHit() == 1)
				goto st;

		}


		int i, j;
	st:
		mouse = GetMouseMsg();
		i = ((mouse.y - 43) / 45);
		j = ((mouse.x - 99) / 45);

		//�������
		if (mouse.uMsg == WM_LBUTTONDOWN && GetMap(i, j) != 0)
		{
			BeginBatchDraw();
			music(musicname[2]);
			LoadMap(map);
			c.i = i; c.j = j;
			setlinecolor(RED);
			rectangle(j * 45 + 99, i * 45 + 43, (j + 1) * 45 + 99, (i + 1) * 45 + 43);
			EndBatchDraw();
			k++;
		}

		//������ƶ��հ�λ��
		if (k >= 1 && mouse.uMsg == WM_LBUTTONDOWN && map[(int)i][(int)j] == 0 && mouse.y - 43 >= 0 && mouse.x - 99 >= 0)
		{
			music(musicname[2]);
			a.i = i; a.j = j;
			break;
		}

		//����Ҽ�����
		if (mouse.uMsg == WM_RBUTTONDOWN)
		{
			music(musicname[6]);
			BackMap(map);
		}

		//�򿪰���
		if (mouse.x >= 37 && mouse.x <= 62 && mouse.y >= 291 && mouse.y <= 312)
		{
			otherstart = clock();
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				music(musicname[8]);

				putimage(97, 68, &img[9]);

				goto back;
			}
		}

		//�˳�������ѡ��ģʽ
		if (mouse.x >= 25 && mouse.x <= 75 && mouse.y >= 427 && mouse.y <= 450 && mouse.uMsg == WM_LBUTTONDOWN)
		{
			music(musicname[7]);
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
					map[i][j] = 0;

			return -1;

		}

		//���浱ǰ��Ϸ
		if (mouse.x >= 550 && mouse.x <= 576 && mouse.y >= 385 && mouse.y <= 412 && mouse.uMsg == WM_LBUTTONDOWN)
		{
			music(musicname[7]);
			Save();
			MessageBox(NULL, "����ɹ�", "��ʾ", MB_OK);
			LoadMap(map);
		}

		//��ʾ���а�
		if (mouse.x >= 38 && mouse.x <= 62 && mouse.y >= 351 && mouse.y <= 375 && mouse.uMsg == WM_LBUTTONDOWN)
		{
			music(musicname[8]);

			otherstart = clock();
			putimage(97, 68, &img[11]);
			printRand();

			goto back;
		}

		//�ڲ鿴���а���߰���ʱ������һ��
		if (0)
			while (1)
			{
			back:
				otherstop = clock();
				mousestart += (otherstart - otherstop);
				mouse = GetMouseMsg();

				if (mouse.x >= 405 && mouse.x <= 459 && mouse.y >= 337 && mouse.y <= 394 && mouse.uMsg == WM_LBUTTONDOWN)
				{
					BeginBatchDraw();
					LoadMap(map);
					EndBatchDraw();
					break;
				}
			}
	}
}


//�˵�
int Start_()
{
	while (1)
	{
		MOUSEMSG mouse;
		mouse = GetMouseMsg();

		//��ʼ��Ϸ
		if (mouse.x > 171 && mouse.x < 420 && mouse.y>125 && mouse.y < 225 && mouse.uMsg == WM_LBUTTONDOWN)
		{
			music(musicname[7]);
			putimage(97, 68, &img[14]);

			maptop = 0;
			OldTime = 0;

			while (1)
			{
				mouse = GetMouseMsg();

				if (mouse.x > 99 + 97 && mouse.x < 264 + 97 && mouse.y>97 + 68 && mouse.y < 142 + 68)
				{
					setlinecolor(RED);
					rectangle(96 + 97, 97 + 68, 264 + 97, 142 + 68);
					if (mouse.uMsg == WM_LBUTTONDOWN)
					{
						music(musicname[7]);
						degree = 6;
						break;
					}
				}
				else if (mouse.x > 99 + 97 && mouse.x < 264 + 97 && mouse.y>162 + 68 && mouse.y < 205 + 68)
				{
					setlinecolor(RED);
					rectangle(96 + 97, 162 + 68, 264 + 97, 205 + 68);
					if (mouse.uMsg == WM_LBUTTONDOWN)
					{
						music(musicname[7]);
						degree = 4;
						break;
					}
				}
				else if (mouse.x > 99 + 97 && mouse.x < 264 + 97 && mouse.y>228 + 68 && mouse.y < 272 + 68)
				{
					setlinecolor(RED);
					rectangle(96 + 97, 228 + 68, 264 + 97, 272 + 68);
					if (mouse.uMsg == WM_LBUTTONDOWN)
					{
						music(musicname[7]);
						degree = 2;
						break;
					}
				}
				else
					putimage(97, 68, &img[14]);
			}
			start = clock();
			return 0;
		}

		//������Ϸ
		if (mouse.x > 171 && mouse.x < 420 && mouse.y>283 && mouse.y < 342 && mouse.uMsg == WM_LBUTTONDOWN)
		{
			music(musicname[7]);
			Load();
			start = clock();
			return 1;
		}

		//�鿴���а�
		if (mouse.x >= 38 && mouse.x <= 62 && mouse.y >= 351 && mouse.y <= 375 && mouse.uMsg == WM_LBUTTONDOWN)
		{
			music(musicname[8]);
			putimage(97, 68, &img[11]);
			printRand();
			goto back;
		}

		//�鿴����
		if (mouse.x >= 37 && mouse.x <= 62 && mouse.y >= 291 && mouse.y <= 312)
		{
			if (mouse.uMsg == WM_LBUTTONDOWN)
			{
				music(musicname[8]);
				putimage(97, 68, &img[9]);

				goto back;
			}

		}

		//�ڲ鿴���а���߰���ʱ������һ��
		if (0)
			while (1)
			{
			back:
				mouse = GetMouseMsg();
				if (mouse.x >= 405 && mouse.x <= 459 && mouse.y >= 337 && mouse.y <= 394 && mouse.uMsg == WM_LBUTTONDOWN)
				{
					putimage(0, 0, &img[10]);
					break;
				}
			}
	}

}
