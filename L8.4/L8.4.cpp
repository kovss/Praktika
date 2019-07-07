#include <iostream> 
#include <iomanip>
#include <math.h>
using namespace std;
template <class T> void Vivod(T** ptrA, const int nrow, const int ncol);
template <class T> T One(T** ptrA, const int nrow, const int ncol);
template <class T> T Two(T** ptrA, const int nrow, const int ncol);

int main()
{
	setlocale(LC_ALL, "Rus");
	//////////////////////////////////////////////////////////////////////////////////////
	cout << "������� ���������� ����� � ��������(int): ";
	int nrow, ncol;
	cin >> nrow >> ncol;                                // ���� ����������� �������   
	int** a = new int* [nrow];          // ��������� ������ ��� ��������� �� ������    
	for (int i = 0; i < nrow; i++) a[i] = new int[ncol];     // ������ ��� ������   
	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++) cin >> a[i][j];            // ���� �������    
	Vivod(a, nrow, ncol);
	//////////////////////////////////////////////////////////////////////////////////////
	
	One(a, nrow, ncol); //----���������� �����, ���������� ���� �� ���� ������� �������----
	Two(a, nrow, ncol); //----����� �������, � ������� ��������� ����� ������� ����� ���������� ���������----
	delete[] a;
	 
	//////////////////////////////////////////////////////////////////////////////////////
	cout << "\n������� ���������� ����� � ��������(float): ";
	cin >> nrow >> ncol;                                // ���� ����������� �������   
	float** b = new float* [nrow];          // ��������� ������ ��� ��������� �� ������    
	for (int i = 0; i < nrow; i++) b[i] = new float[ncol];     // ������ ��� ������   
	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++) cin >> b[i][j];            // ���� �������    
	Vivod(b, nrow, ncol);
	//////////////////////////////////////////////////////////////////////////////////////

	One(b, nrow, ncol); //----���������� �����, ���������� ���� �� ���� ������� �������----
	Two(b, nrow, ncol); //----����� �������, � ������� ��������� ����� ������� ����� ���������� ���������----
	delete[] b;

	return 0;
	system("pause");
}


template <class T> void Vivod(T** ptrA, const int nrow, const int ncol) {
	for (int i = 0; i < nrow; i++) {                         // ����������� �����
		for (int j = 0; j < ncol; j++) cout << setw(4) << ptrA[i][j] << "  ";
		cout << endl;
	}
	return;
}


template <class T> T One(T** ptrA, const int nrow, const int ncol) {
	int kol = 0;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++)
			if (ptrA[i][j] == 0) {
				kol++;
				break;
			}
	cout << "���������� �����, ���������� ���� �� ���� ������� �������:" << kol << endl;
	return 0;
}


template <class T> T Two(T** ptrA, const int nrow, const int ncol) {
	T maxs = 0, maxj; //int
	for (int j = 0; j < ncol; j++) {
		T buf = ptrA[0][j]; //int
		int kol = 1;
		for (int i = 1; i < nrow; i++) {
			if (ptrA[i][j] == buf) {
				kol++;
				if (kol > maxs) {
					maxs = kol;
					maxj = j;
				}
			}
			else {
				buf = ptrA[i][j];
				kol = 1;
			}
		}
	}

	cout << "����� ������: " << maxj << endl;
	cout << "����� ������� ����� ���������: " << maxs << endl;
	return 0;
}