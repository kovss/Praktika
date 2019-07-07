#include <iostream>
#include<math.h>
using namespace std;
template <class T> T Vivod(T* ptrA, const int n);
template <class T> T zad_POISK(T* ptrA, const int n);
template <class T> T zad_SUM(T* ptrA, const int n);
template <class T> T zad_SORT(T* ptrA, const int n);


int main() {
	int n;
	setlocale(LC_ALL, "Rus");
	///////////////////////////////////////////////////////////////////////////////////
	cout << " ������� ���������� ���������(double): "; cin >> n;
	double* a = new double[n];
	cout << " ������� �������� �������: ";
	for (int i = 0; i < n; i++) cin >> a[i];
	Vivod(a, n);
	////////////////////////////////////////////////////////////////////////////////////
	//���� 1-�� �������: ����� ���������� ��������� �������, ������� �
	zad_POISK(a, n);
	//���� 2-�� �������: ����� ����� ����� ������ ��������� �������, ������������� ����� ���������� �������������� ��������.
	zad_SUM(a, n);
	//���� 3-�� �������: ������������� ������ ����� �������, ����� ������� ������������� ��� ��������, ������������ �� ������������� �� ����� ��� �� 20 %, � ����� � ��� ���������.
	zad_SORT(a, n);

	////////////////////////////////////////////////////////////////////////////////////
	cout << "������� ���������� ��������� �������(int): "; cin >> n;
	int* b = new int[n];
	cout << " ������� �������� �������: ";
	for (int i = 0; i < n; i++) cin >> b[i];
	Vivod(b, n);
	/////////////////////////////////////////////////////////////////////////////////////
	//���� 1-�� �������
	zad_POISK(b, n);
	//���� 2-�� �������
	zad_SUM(b, n);
	//���� 3-�� �������
	zad_SORT(b, n);

	delete[] a; delete[] b;
	return 0;
	system("pause");
}

template <class T> T zad_POISK(T* ptrA, const int n) {
	int c;
	cout << "\n������� C :"; cin >> c;
	int k = 0; // ������� ��-�� ������ �
	for (int i = 0; i < n; i++)
		if (ptrA[i] < c) k++;
	cout << "���-�� ��������� ������ � = " << k;
	return k;
}
template <class T> T zad_SUM(T* ptrA, const int n) {
	int ineg = -1;
	for (int i = 0; i < n; i++) if (ptrA[i] < 0) ineg = i;
	if (ineg == -1) cout << "\n������������� ��������� ���!\n";
	else if (ineg == n - 1) cout << "\n������������� ������� - ���������!\n";
	else {
		int sum = 0;
		for (int i = ineg + 1; i < n; i++) sum += (int)ptrA[i];
		cout << " \n����� ����� ���������� �����. ��������: " << sum;
		return sum;
	}
}
template <class T> T zad_SORT(T* ptrA, const int n) {
	int imax = 0;
	for (int i = imax = 0; i < n; i++) {
		if (ptrA[i] > ptrA[imax]) imax = i;
	}
	double twenty = ptrA[imax] - ptrA[imax] * 0.2; // ������� �����, ������� ���������� �� ������������� ����� �� 20%,
											//  �������� ��������� ��� ���������� �������
	cout << "\n max= " << ptrA[imax] << "\n -20% �� max:" << twenty << endl;
	for (int i = 0; i < n; i++)
		if (ptrA[i] >= twenty)
			cout << ptrA[i] << " ";
	for (int i = 0; i < n; i++)
		if (!(ptrA[i] >= twenty))
			cout << ptrA[i] << " ";
	cout << endl;
	return 0;
}
template <class T> T Vivod(T* ptrA, const int n) {
	cout << " � = ";
	for (int i = 0; i < n; i++) cout << ptrA[i] << " ";
	return 1;
}