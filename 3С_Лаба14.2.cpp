#include <stdio.h>	//основная библиотека 
#include <iostream>
#include <string> 
#include <math.h>	//нужна для подсчета sin(x),cos(x)

//число пи
const double M_PI = 3.14159265358979323846;

//вункция
double F(double x) { return 2 * sin(x) + 3 * cos(2 * x); }
void диограмма(double ax, double bx, int nx, int ny);
void гистограмма(double ax, double bx, int nx, int ny);
int main()
{
	//границы по х
	double ax = -M_PI / 2;
	double bx = M_PI / 2;
	//размерность
	int nx = 78;
	int ny = 25;
	диограмма(ax, bx, nx, ny);
	//размерность для гистограммы
	nx = 60; ny = 80;
	гистограмма(ax, bx,nx, ny);
}
void диограмма(double ax, double bx,int nx, int ny) {
	//поиск границ у
	double min = F(ax);
	double max = F(ax);
	double шагx = (bx - ax) / (nx);
	for (double x = ax; x <= bx; x = x + шагx)
	{
		if (F(x) > max)
			max = F(x);
		if (F(x) < min)
			min = F(x);
	}
	//расчот шага
	double шагy = (max - min) / ny;
	//ходим по у
	for (double y = max; y >= min - шагy * 0.001; y = y - шагy)
	{
		//удаление сдвига из-зи знаки -
		if(y >= 0) printf(" ");
		//значение у
		printf("%.2f%c", y, char(179));
		//печать х
		for (double Fx, x = ax; x <= bx - шагx * 0.001; x = x + шагx)
		{
			Fx = F(x);
			//ось графика
			if (x > 0 - шагx / 2 && x < 0 + шагx / 2)
				printf("%c", char(197));
			else if (y > 0 - шагy / 2 && y < 0 + шагy / 2)
				printf("%c", char(196));
			//если у близок к f(x)
			else if (y > Fx - шагy / 2 && y < Fx + шагy /2)
					printf("x");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void гистограмма(double ax, double bx, int nx, int ny) {
	FILE* out = fopen("Text.txt", "w");		//открываем файл для записи

	const int высота_карты = 12;
	const int ширина_карты = 480;

	string Карта[высота_карты] = {
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                                                           C                                                                                                                                                              C                              C    ]                      C                                                                                                                                                                                       B",
"B                                                                                                                                                                                                                                          C                              C          C                                                                                                                                                                                                        B",
"B                                                                                                                                                                                                                                          C                             CCCCCCCCCCCC            C                                                                                                                                                                                            B",
"B                                      00                                                                                                                                                                                                         CCCCCCCCCC             C             C          C                                                                                                                                                                                           B",
"B   C       0000                                                                                                                              BBBB  BB                            BB                                                              C                            0        C  [  C    C                                                                                                                                                                                          B",
"B H                                  111111                                                BBB          BBB                               B        BBB                          B  B                                                       CCCCCC     C i    C            C          CCCCCCCC    C                                                                                                                                                                                            B",
"BBB                                11     11  1111                                       BB    q      BBB     BB                       B   r         BBB                       B    B                                                      C          CCCCCCC        CCCCCCCC           C     s C      C                                                                                                                                                                                      B",
"B              BB                11                 11                                   BBBBBBBBBBBBB                               BBBBBBBB              BB    BB          B      B                         BBBB                 CCCCCCCCC              C     o             C          CCCCCCCC     C                                                                                                                                                                                       B",
"B              BB               1                     11                      BBBBBBBBBBB                         BBB             B0                     BBBB    B          B    0    B         BBBBBBBBBBB    BBBBB                                        CCCCCCCCCCCCCCCCCC     C     P   C  d      C                                                                                                                                                                                      B",
"B  n  B    BBBBB BBBBB           1         a            11       b            B            w           0 B            BBB           B    e                 BBB   t          B y                    u               BBBBBB                                         C                CCCCCCCCCCCCCCCCCCCCCCCCCCC                                                                                                                                                                                B",
"11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111122211111111111111112221111111111111111111111111111111111111111111111111111111111111111111111111222111111111111111111111111222222222222222222222222222222222222222222222222222222222222222222222222222222111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
	};

	fprintf(out, "|");
	//поиск границ у
	double min = F(ax);
	double max = F(ax);
	double шагx = (bx - ax) / (nx);
	for (double x = ax; x <= bx; x = x + шагx)
	{
		if (F(x) > max)
			max = F(x);
		if (F(x) < min)
			min = F(x);
	}
	//расчет шага
	double шагy = (max - min) / (ny);
	//ход по х
	for (double Fx, x = ax; x <= bx ; x = x + шагx)
	{
		Fx = F(x);
		//удаление сдвига
		if(F(x) >0) fprintf(out, "        ");
		//ход по х
		for (double y = min; y < max - 0.000001; y = y + шагy)
		{
			//если близок к 0 ресуем ось
			if (y > 0 - шагy / 2 && y < 0 + шагy / 2)
				fprintf(out, "|");
			else if (x > 0 - шагx / 2 && x < 0 + шагx / 2)
				fprintf(out, "-");
			//у меньше 0 и больше f(x)
			else if (y + шагy / 2 > Fx && y < 0)
			{
				//печать числа
				fprintf(out, "%.4f ", y);
				//заполняем игриками до 0
				while (y < 0)
				{
					fprintf(out, "y");
					y = y + шагy;
				}
				fprintf(out, "|");
			}
			else if (y > 0)
				//заполняем игриками пока у < f(x)
				while (y + 0.00001 < Fx) {
					fprintf(out, "y");
					y = y + шагy;
				}
			else if(y<0)
				fprintf(out, " ");
		}
		if (F(x) > 0) fprintf(out, " %.4f ", Fx);
		fprintf(out, "\n");
	}
	//удаление сдвига графика из-за печати цифр
	fprintf(out, "        ");
	//------------маштаб вункции по у
	//  |-----|-----|
	int i = 0;
	for (double y = min; y < max - шагy - 0.000001; y = y + шагy)
	{
		if (i % 10 == 0)
			fprintf(out, "|");
		else
			fprintf(out, "-");
		i++;
	}fprintf(out, "|");
	//соответствующие значения ф-ии
	fprintf(out, "\n        "); i = 0;
	for (double y = min; y < max - шагy - 0.000001; y = y + шагy)
	{
		if (y < 0 && i % 10 == 0)
			fprintf(out, "%.1f", y);
		else if (y > 0 && i % 10 == 0)
			fprintf(out, "%.1f ", y);
		else if (i % 10 >= 4)
			fprintf(out, " ");
		i++;
	}fprintf(out, "%.1f", max);
}
