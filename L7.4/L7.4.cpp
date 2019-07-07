#include <iostream> 
#include <iomanip>
#include <math.h>
using namespace std;
void Vivod(int** a, const int nrow, const int ncol);
void One(int** a, const int nrow, const int ncol);
void Two(int** a, const int nrow, const int ncol);


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ����� � ��������: ";
	int nrow, ncol;
	cin >> nrow >> ncol;                                // ���� ����������� �������   
	int** a = new int* [nrow];          // ��������� ������ ��� ��������� �� ������    
	for (int i = 0; i < nrow; i++) a[i] = new int[ncol];     // ������ ��� ������   
	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++) cin >> a[i][j];            // ���� �������    
	Vivod(a, nrow, ncol);
	//----���������� �����, ���������� ���� �� ���� ������� �������----
	One(a, nrow, ncol);
	

	//----����� �������, � ������� ��������� ����� ������� ����� ���������� ���������----
	Two(a, nrow, ncol);
	

	system("pause");
}
void Vivod(int** a, const int nrow, const int ncol){
for (int i = 0; i < nrow; i++) {                         // ����������� �����
		for (int j = 0; j < ncol; j++) cout << setw(4) << a[i][j] << "  ";
		cout << endl;
	}
return;
}
void One(int** a, const int nrow, const int ncol){
int kol = 0;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++)
			if (a[i][j] == 0) {
				kol++;
				break;
			}
	cout << "���������� �����, ���������� ���� �� ���� ������� �������:" << kol << endl;
	return;
}
void Two(int** a, const int nrow, const int ncol){
int maxs = 0, maxj;
	for (int j = 0; j < ncol; j++) {
		int buf = a[0][j];
		int kol = 1;
		for (int i = 1; i < nrow; i++) {
			if (a[i][j] == buf) {
				kol++;
				if (kol > maxs) {
					maxs = kol;
					maxj = j;
				}
			}
			else {
				buf = a[i][j];
				kol = 1;
			}
		}
	}

	cout << "����� ������: " << maxj << endl;
	cout << "����� ������� ����� ���������: " << maxs << endl;
	return;
}