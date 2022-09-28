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

int maze::put_water(int p, int count)// p��ʾ��ǰλ�ã�count���record��¼��Ѱ�ҵ�·��
{
	int new_p;

	while (map[p - 1] + map[p - 16] + map[p + 1] + map[p + 16] == 1) //�����ǰλ�ò��ǲ�·�ڣ���һֱ��¼ֱ������·�ڻ����Ϊֹ
	{
		if (p == Exit)
        {
            record[count] = 0;
            return 1;
        }
		map[p] = 0; //������whileѭ����������һֱ��ˮ�����������·
		new_p = (p - 1)*map[p - 1] + (p - 16)*map[p - 16] + (p + 1)*map[p + 1] + (p + 16)*map[p + 16]; //Ѱ�ҵ���·����һ���ڵ�	
		record[count] = new_p - p; //��¼�����������·���߷�
		count++;
		p = new_p;
	}
	map[p] = 0;
	if (map[p - 1] + map[p - 16] + map[p + 1] + map[p + 16] > 1) //�����ʾ���·�����ڲ�·�ڣ�����������ѡ�����������ѡ��
	{
		if (1 == map[p - 1]) //������Ѱ�ң����ʽΪ���ʾ������·
		{
			record[count] = -1;
			if (1 == put_water(p - 1, count + 1)) //��Ȼ������·���͵ݹ�����������������·������
				return 1;
		}
		if (1 == map[p - 16]) //������Ѱ�ң����ʽΪ���ʾ����·
		{
			record[count] = -16;
			if (1 == put_water(p - 16, count + 1)) //ͬ��
				return 1;
		}
		if (1 == map[p + 1]) //������Ѱ�ң����ʽΪ���ʾ�ҷ���·
		{
			record[count] = 1;
			if (1 == put_water(p + 1, count + 1))
				return 1;
		}
		if (1 == map[p + 16]) //�������Ѱ�ң����ʽΪ���ʾ������·
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
	printf("\n\n�������ܵ�·���ǣ�\n");
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
		printf("�Թ��������");
		return 0;
	}
	else  m.showpath(MAPARR);

	return 0;
}
