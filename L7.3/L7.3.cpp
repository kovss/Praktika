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
	cout << " Введите количество элементов: "; cin >> n;
	double* a = new double[n];
	cout << " Введите элементы массива: ";
	for (int i = 0; i < n; i++) cin >> a[i];
	Vivod(a, n);
	//Блок 1-го задания: Найти количество элементов массива, меньших С
	 zad_POISK(a,n);
	//Блок 2-го задания: Найти сумму целых частей элементов массива, расположенных после последнего отрицательного элемента.
	 zad_SUM(a,n);
	//Блок 3-го задания: Преобразовать массив таким образом, чтобы сначала располагались все элементы, отличающиеся от максимального не более чем на 20 %, а потом — все остальные.
	 zad_SORT(a,n);
	system("pause");
}

double zad_POISK(const double* const a, const int n) {
int c;
	cout << "\nВведите C :"; cin >> c;
	int k = 0; // счетчик эл-ов меньше с
	for (int i = 0; i < n; i++)
		if (a[i] < c) k++;
	cout << "Кол-во элементов меньше С = " << k;
	return k;
}
int zad_SUM(const double* const a, const int n) {
	int ineg = -1;
	for (int i = 0; i < n; i++) if (a[i] < 0) ineg = i;
	if (ineg == -1) cout << "\nОтрицательных элементов нет!\n";
	else if (ineg == n - 1) cout << "\nОтрицательный элемент - последний!\n";
	else {
		int sum = 0;
		for (int i = ineg + 1; i < n; i++) sum += (int)a[i];
		cout << " \nСумма после последнего отриц. элемента: " << sum;
		return sum;
	}
}
void zad_SORT(double* const a, const int n) {
int imax = 0;
	for (int i = imax = 0; i < n; i++) {
		if (a[i] > a[imax]) imax = i;
	}
	double twenty = a[imax] - a[imax] * 0.2; // находим число, которое отличается от максимального ровно на 20%,
											//  послужит критерием для сортировки массива
	cout << "\n max= " << a[imax] << "\n -20% от max:" << twenty << endl;
	for (int i = 0; i < n; i++)
		if (a[i] >= twenty )
			cout << a[i] << " ";
	for (int i = 0; i < n; i++)
		if (!(a[i] >= twenty))
			cout << a[i] << " ";
	return;
}
void Vivod(const double* const a, const int n) {
cout << " а = ";
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return;
}