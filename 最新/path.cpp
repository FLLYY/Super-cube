#include"path.h"
#include"bfspath.h"
#include"mappath.h"


//Ѱ·�㷨��ѡ��
int Path(int x1, int y1, int x2, int y2)
{
	if (JugeDeafet(map) < 79)
	{
		return  MapPath1(x1, y1, x2, y2);
	}
	else
	{
		return  getPath(x1, y1, x2, y2);
	}
}
