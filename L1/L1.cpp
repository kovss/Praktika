#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
int main()
{
	int a;
	double z1, z2;
	printf("Input integer value a\n");
	scanf("%d", &a);
	z1 = (((a + 2) / (sqrt(2 * a))) - (a / (sqrt(2 * a) + 2)) + ( 2 / (a - sqrt(2 * a)))) * (sqrt(a) - sqrt(2)) / (a + 2);
	z2 = 1 / (sqrt(a) + sqrt(2));
	printf("z1(%d) = %f\n", a, z1);
	printf("z2(%d) = %f\n",a, z2);
	_getch();
}