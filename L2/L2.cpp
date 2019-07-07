#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	const int MaxIter = 500; // ������������ ���������� ��������
	bool done = true; // ������� ��������� ����������
	double x1, x2, dx, eps;
	cout << "\n������� X���, X���, ��� dX � ��������: ";
	cin >> x1 >> x2 >> dx >> eps;
	cout << "\n�\tX\tY\t\tK\tCh\n";
	cout << "--------------------------------------------------\n";
	int k;			// ��� ������ ������ ��������� ����� ����
	double c;			// ��� ������ �������� ��������� ����� ����
	int i = 0;
	for (double x = x1; x <= x2; x += dx) {
		double ch = 1 / pow(3, (double)1 / 2);	// ������ ���� ����
		double y = ch;				// ��������� �������� �����
		int n = 0;					// ����� ����� ����
		k = 0;
		while (fabs(ch) > eps && n < MaxIter) {
			//���� n > MaxIter ��� ���������� ��� �������� ��������
			double T = -x * pow(3, (1 / (double)(n * n + 5 * n + 6)));
			ch *= T;				// ��������� ���� ����
			y += ch;				// ���������� ����� ���� � �����
			n++;					// ����� ������ ����� ����
		}
		k = n; c = ch;				// �������� ���������� ����� ����
		
	if (done) {
		cout << ++i << "\t" << x << "\t" << y << "   \t";
		cout << k << "\t" << c << "\n";
	}}
	system("pause");
}
