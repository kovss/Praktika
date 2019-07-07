#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
void Function(double x, double eps);

int main() {
	setlocale(LC_ALL, "ru");
	
	double x1, x2, dx, eps;
	cout << "\nВведите Xнач, Xкон, шаг dX и точность: ";
	cin >> x1 >> x2 >> dx >> eps;
	cout << "\n№\tX\tY\t\tK\tCh\n";
	cout << "--------------------------------------------------\n";
	int k;			// для вывода номера конечного члена ряда
	double c;			// для вывода значения конечного члена ряда
	
	for (double x = x1; x <= x2; x += dx) {
		Function(x, eps);
	}
	system("pause");
}

void Function(double x, double eps) {
	const int MaxIter = 500;
	bool done = true; // признак успешного вычисления
	double ch = 1 / pow(3, (double)1 / 2);	// первый член ряда
	double y = ch;				// начальное значение суммы
	int n = 0;					// номер члена ряда
	int i = 0;
	while (fabs(ch) > eps && n < MaxIter) {
		//Если n > MaxIter ряд расходится или сходится медленно
		double T = -x * pow(3, (1 / (double)(n * n + 5 * n + 6)));
		ch *= T;				// очередной член ряда
		y += ch;				// добавление члена ряда к сумме
		n++;					// номер нового члена ряда
	}
	
	if (done) {
		cout << ++i << "\t" << x << "\t" << y << "   \t";
		cout << n << "\t" << ch << "\n"; 
	}
	return;
}