#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	const int MaxIter = 500; // ограничитель количества итераций
	bool done = true; // признак успешного вычисления
	double x1, x2, dx, eps;
	cout << "\nВведите Xнач, Xкон, шаг dX и точность: ";
	cin >> x1 >> x2 >> dx >> eps;
	cout << "\n№\tX\tY\t\tK\tCh\n";
	cout << "--------------------------------------------------\n";
	int k;			// для вывода номера конечного члена ряда
	double c;			// для вывода значения конечного члена ряда
	int i = 0;
	for (double x = x1; x <= x2; x += dx) {
		double ch = 1 / pow(3, (double)1 / 2);	// первый член ряда
		double y = ch;				// начальное значение суммы
		int n = 0;					// номер члена ряда
		k = 0;
		while (fabs(ch) > eps && n < MaxIter) {
			//Если n > MaxIter ряд расходится или сходится медленно
			double T = -x * pow(3, (1 / (double)(n * n + 5 * n + 6)));
			ch *= T;				// очередной член ряда
			y += ch;				// добавление члена ряда к сумме
			n++;					// номер нового члена ряда
		}
		k = n; c = ch;				// фиксация последнего члена ряда
		
	if (done) {
		cout << ++i << "\t" << x << "\t" << y << "   \t";
		cout << k << "\t" << c << "\n";
	}}
	system("pause");
}
