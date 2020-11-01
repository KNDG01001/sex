#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#pragma warning(disable :4996)
void draw(int a[30][30])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (a[i][j] == 0)
				printf("��");
			else if (a[i][j] == 1)
				printf("*");
			else if (a[i][j] == 2)
				printf("o");
		}
		printf("\n");
	}
}

int main(void)
{
	int map[30][30];
	int hide[30][30];
	srand((unsigned)time(NULL));
	int a, b, c, d, k;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			map[i][j] = 0;
			hide[i][j] = 0;
		}
	}
	printf("���� ���� �Է�(30*30)\n");
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		while (1)
		{
			a = rand() % 30;
			b = rand() % 30;
			if (map[a][b] == 1);
			else
			{
				map[a][b] = 1;
				break;
			}
		}
		map[a][b] = 1;
	}
	while (1)
	{
		draw(hide);
		printf("X��ǥ �Է�: ");
		scanf("%d", &c);
		printf("Y��ǥ �Է�: ");
		scanf("%d", &d);

		c--;
		d--;

		if (c >= 30 || d >= 30 || c < 0 || d < 0)
		{
			printf("�������� ���ڸ� �Է����ּ���\n");
			Sleep(1000);
		}
		else if (map[c][d] == 1)
		{
			hide[c][d] = 1;
			system("cls");
			draw(hide);
			printf("��!\n");
			Sleep(2000);
			break;
		}
		else if (hide[c][d] == 2)
		{
			printf("�ߺ�\n");
		}
		else if (map[c][d] == 0)
		{
			printf("����!\n");
			hide[c][d] = 2;
		}

		Sleep(1000);
		system("cls");
	}
	printf("������ġ\n");
	draw(map);
}