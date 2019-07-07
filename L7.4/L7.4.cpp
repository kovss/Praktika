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
	cout << "Введите количество строк и столбцов: ";
	int nrow, ncol;
	cin >> nrow >> ncol;                                // ввод размерности массива   
	int** a = new int* [nrow];          // выделение памяти под указатели на строки    
	for (int i = 0; i < nrow; i++) a[i] = new int[ncol];     // память под строки   
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++) cin >> a[i][j];            // ввод массива    
	Vivod(a, nrow, ncol);
	//----Количество строк, содержащих хотя бы один нулевой элемент----
	One(a, nrow, ncol);
	

	//----Номер столбца, в котором находится самая длинная серия одинаковых элементов----
	Two(a, nrow, ncol);
	

	system("pause");
}
void Vivod(int** a, const int nrow, const int ncol){
for (int i = 0; i < nrow; i++) {                         // контрольный вывод
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
	cout << "Количество строк, содержащих хотя бы один нулевой элемент:" << kol << endl;
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

	cout << "Номер стобца: " << maxj << endl;
	cout << "Самая длинная серия элементов: " << maxs << endl;
	return;
}