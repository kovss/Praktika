#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
void Function(double x, double eps);

int main() {
	setlocale(LC_ALL, "ru");
	
	double x1, x2, dx, eps;
	cout << "\n������� X���, X���, ��� dX � ��������: ";
	cin >> x1 >> x2 >> dx >> eps;
	cout << "\n�\tX\tY\t\tK\tCh\n";
	cout << "--------------------------------------------------\n";
	int k;			// ��� ������ ������ ��������� ����� ����
	double c;			// ��� ������ �������� ��������� ����� ����
	
	for (double x = x1; x <= x2; x += dx) {
		Function(x, eps);
	}
	system("pause");
}

void Function(double x, double eps) {
	const int MaxIter = 500;
	bool done = true; // ������� ��������� ����������
	double ch = 1 / pow(3, (double)1 / 2);	// ������ ���� ����
	double y = ch;				// ��������� �������� �����
	int n = 0;					// ����� ����� ����
	int i = 0;
	while (fabs(ch) > eps && n < MaxIter) {
		//���� n > MaxIter ��� ���������� ��� �������� ��������
		double T = -x * pow(3, (1 / (double)(n * n + 5 * n + 6)));
		ch *= T;				// ��������� ���� ����
		y += ch;				// ���������� ����� ���� � �����
		n++;					// ����� ������ ����� ����
	}
	
	if (done) {
		cout << ++i << "\t" << x << "\t" << y << "   \t";
		cout << n << "\t" << ch << "\n"; 
	}
	return;
}