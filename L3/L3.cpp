#include <iostream>
#include<math.h>
using namespace std;
int main() {
	int n;
	setlocale(LC_ALL, "Rus");
	cout << " ������� ���������� ���������: "; cin >> n;
	double* a = new double[n];
	cout << " ������� �������� �������: ";
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << " � = ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	//���� 1-�� �������: ����� ���������� ��������� �������, ������� �
	int c;
	cout << "\n������� C :"; cin >> c;
	int k = 0; // ������� ��-�� ������ �
	for (int i = 0; i < n; i++) 
		if (a[i] < c) k++;
	cout << "���-�� ��������� ������ � = " << k;
	//���� 2-�� �������: ����� ����� ����� ������ ��������� �������, ������������� ����� ���������� �������������� ��������.
	int ineg = -1;
	for (int i = 0; i < n; i++) if (a[i] < 0) ineg = i;
	if (ineg == -1) cout << "\n������������� ��������� ���!\n";
	else if (ineg == n - 1) cout << "\n������������� ������� - ���������!\n";
	else {
		int sum = 0;
		for (int i = ineg + 1; i < n; i++) sum += (int)a[i];
		cout << " \n����� ����� ���������� �����. ��������: " << sum;
	}
	//���� 3-�� �������: ������������� ������ ����� �������, ����� ������� ������������� ��� ��������, ������������ �� ������������� �� ����� ��� �� 20 %, � ����� � ��� ���������.
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
	system("pause");
}