#include <iostream>
#include<math.h>
using namespace std;
void Vivod(const double* const a, const int n);
double zad_POISK(const double* const a, const int n);
int zad_SUM(const double* const a, const int n);
void zad_SORT(double* const a, const int n);


int main() {
	int n;
	setlocale(LC_ALL, "Rus");
	cout << " ������� ���������� ���������: "; cin >> n;
	double* a = new double[n];
	cout << " ������� �������� �������: ";
	for (int i = 0; i < n; i++) cin >> a[i];
	Vivod(a, n);
	//���� 1-�� �������: ����� ���������� ��������� �������, ������� �
	 zad_POISK(a,n);
	//���� 2-�� �������: ����� ����� ����� ������ ��������� �������, ������������� ����� ���������� �������������� ��������.
	 zad_SUM(a,n);
	//���� 3-�� �������: ������������� ������ ����� �������, ����� ������� ������������� ��� ��������, ������������ �� ������������� �� ����� ��� �� 20 %, � ����� � ��� ���������.
	 zad_SORT(a,n);
	system("pause");
}

double zad_POISK(const double* const a, const int n) {
int c;
	cout << "\n������� C :"; cin >> c;
	int k = 0; // ������� ��-�� ������ �
	for (int i = 0; i < n; i++)
		if (a[i] < c) k++;
	cout << "���-�� ��������� ������ � = " << k;
	return k;
}
int zad_SUM(const double* const a, const int n) {
	int ineg = -1;
	for (int i = 0; i < n; i++) if (a[i] < 0) ineg = i;
	if (ineg == -1) cout << "\n������������� ��������� ���!\n";
	else if (ineg == n - 1) cout << "\n������������� ������� - ���������!\n";
	else {
		int sum = 0;
		for (int i = ineg + 1; i < n; i++) sum += (int)a[i];
		cout << " \n����� ����� ���������� �����. ��������: " << sum;
		return sum;
	}
}
void zad_SORT(double* const a, const int n) {
int imax = 0;
	for (int i = imax = 0; i < n; i++) {
		if (a[i] > a[imax]) imax = i;
	}
	double twenty = a[imax] - a[imax] * 0.2; // ������� �����, ������� ���������� �� ������������� ����� �� 20%,
											//  �������� ��������� ��� ���������� �������
	cout << "\n max= " << a[imax] << "\n -20% �� max:" << twenty << endl;
	for (int i = 0; i < n; i++)
		if (a[i] >= twenty )
			cout << a[i] << " ";
	for (int i = 0; i < n; i++)
		if (!(a[i] >= twenty))
			cout << a[i] << " ";
	return;
}
void Vivod(const double* const a, const int n) {
cout << " � = ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return;
}