#include <iostream>
using namespace std;
class maze
{
public:
	int i;
	maze(int m[], int r[], int , int );
	int put_water(int, int);
	void showpath(int *);
protected:
	int map[256], record[256], Start, Exit;
};
maze::maze(int m[], int r[], int s, int e)
{
	for (i = 0; i < 256; i++)
	{
		map[i] = m[i];

		if (i % 16 == 0)  printf("\n");

		if (m[i])  printf(" ");
		else printf("*");
	}
	for (i = 0; i < 256; i++)  record[i] = r[i];
	Start = s;
	Exit = e;
}

int maze::put_water(int p, int count)// p表示当前位置，count配合record记录以寻找的路径
{
	int new_p;

	while (map[p - 1] + map[p - 16] + map[p + 1] + map[p + 16] == 1) //如果当前位置不是岔路口，则一直记录直至到岔路口或出口为止
	{
		if (p == Exit)
        {
            record[count] = 0;
            return 1;
        }
		map[p] = 0; //配合这个while循环，就这样一直把水灌满这个单向路
		new_p = (p - 1)*map[p - 1] + (p - 16)*map[p - 16] + (p + 1)*map[p + 1] + (p + 16)*map[p + 16]; //寻找单向路的下一个节点	
		record[count] = new_p - p; //记录下来这个单向路的走法
		count++;
		p = new_p;
	}
	map[p] = 0;
	if (map[p - 1] + map[p - 16] + map[p + 1] + map[p + 16] > 1) //这里表示这个路口属于岔路口，至少有两个选择，最多有三个选择
	{
		if (1 == map[p - 1]) //先往上寻找，表达式为真表示上面有路
		{
			record[count] = -1;
			if (1 == put_water(p - 1, count + 1)) //既然上面有路，就递归调用自身，看看上面的路情况如何
				return 1;
		}
		if (1 == map[p - 16]) //再往左寻找，表达式为真表示左方有路
		{
			record[count] = -16;
			if (1 == put_water(p - 16, count + 1)) //同上
				return 1;
		}
		if (1 == map[p + 1]) //再往右寻找，表达式为真表示右方有路
		{
			record[count] = 1;
			if (1 == put_water(p + 1, count + 1))
				return 1;
		}
		if (1 == map[p + 16]) //最后往下寻找，表达式为真表示下面有路
		{
			record[count] = 16;
			if (1 == put_water(p + 16, count + 1))
				return 1;
		}
	}

	return 0;
}

void maze::showpath(int m[])
{
	printf("\n\n我们逃跑的路径是：\n");
	for (i = 0; i < 256; i++) 
	{
		map[i] = m[i];
	}
	map[10] = -9;
	for (i = 0; record[i]; i++)
	{
		Start += record[i];
		map[Start]++;
	}
	for (i = 0; i < 256; i++)
	{

		if (i % 16 == 0)  printf("\n");

		switch (map[i])
		{
		case 0:
			printf("*");
			break;
		case 1:
			printf(" ");
			break;
		case 2:
			printf("-");
			break;
		case 9:
			printf("1");
			break;
		case -9:
			printf("2");
		}
	}
}
int MAPARR[256] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0,
	0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0,
	0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0,
	0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0,
	0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0,
	0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
	0, 1, 1, 1, 0, 9, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0,
	0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0,
	0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
	0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0,
	0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0,
	0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}, RECORD[256];
int main()
{
	maze m(MAPARR,RECORD,149,26);

	if (0 == m.put_water(149, 0))
	{
		printf("迷宫设计有误！");
		return 0;
	}
	else  m.showpath(MAPARR);

	return 0;
}
