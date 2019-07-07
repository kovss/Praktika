#include <iostream> 
#include <stdio.h>
#include <math.h>
#pragma warning(disable : 4996)
using namespace std;

double Rachet_Z1 (const int a); 
double Rachet_Z2 (const int a);
int main()
{
	int a;
	printf("Input integer value a\n");
	scanf("%d", &a);


	cout << "z1 = " << Rachet_Z1(a) << endl;
	cout << "z2 = " << Rachet_Z2(a) << endl;

	system("pause");
	return 0;
}




double Rachet_Z1(const int a) {
	return (((a + 2) / (sqrt(2 * a))) - (a / (sqrt(2 * a) + 2)) + (2 / (a - sqrt(2 * a)))) * (sqrt(a) - sqrt(2)) / (a + 2);
}

double Rachet_Z2(const int a) {
	return 1 / (sqrt(a) + sqrt(2));
}
