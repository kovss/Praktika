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
	cout << "Введите количество строк и столбцов(int): ";
	int nrow, ncol;
	cin >> nrow >> ncol;                                // ввод размерности массива   
	int** a = new int* [nrow];          // выделение памяти под указатели на строки    
	for (int i = 0; i < nrow; i++) a[i] = new int[ncol];     // память под строки   
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++) cin >> a[i][j];            // ввод массива    
	Vivod(a, nrow, ncol);
	//////////////////////////////////////////////////////////////////////////////////////
	
	One(a, nrow, ncol); //----Количество строк, содержащих хотя бы один нулевой элемент----
	Two(a, nrow, ncol); //----Номер столбца, в котором находится самая длинная серия одинаковых элементов----
	delete[] a;
	 
	//////////////////////////////////////////////////////////////////////////////////////
	cout << "\nВведите количество строк и столбцов(float): ";
	cin >> nrow >> ncol;                                // ввод размерности массива   
	float** b = new float* [nrow];          // выделение памяти под указатели на строки    
	for (int i = 0; i < nrow; i++) b[i] = new float[ncol];     // память под строки   
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < nrow; i++)
		for (int j = 0; j < ncol; j++) cin >> b[i][j];            // ввод массива    
	Vivod(b, nrow, ncol);
	//////////////////////////////////////////////////////////////////////////////////////

	One(b, nrow, ncol); //----Количество строк, содержащих хотя бы один нулевой элемент----
	Two(b, nrow, ncol); //----Номер столбца, в котором находится самая длинная серия одинаковых элементов----
	delete[] b;

	return 0;
	system("pause");
}


template <class T> void Vivod(T** ptrA, const int nrow, const int ncol) {
	for (int i = 0; i < nrow; i++) {                         // контрольный вывод
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
	cout << "Количество строк, содержащих хотя бы один нулевой элемент:" << kol << endl;
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

	cout << "Номер стобца: " << maxj << endl;
	cout << "Самая длинная серия элементов: " << maxs << endl;
	return 0;
}