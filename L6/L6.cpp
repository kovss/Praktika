#include <windows.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#pragma warning(disable : 4996)


using namespace std;



int main() {
	setlocale(LC_ALL, "RUS");		// ��� RUS ��������� ������ ������������ (,) 
	const int len_name = 8, len_shop = 11, len_cena = 7;
	const int len_buff = len_name + len_shop + len_cena + 3;
	char buf[len_buff];				// ����� ��� ����� ������ �� �����

	struct PRICE {
	char Tovar[len_name + 1];
	char Magazin[len_shop + 1];
	double Cena;
};
	const int l_dbase = 8;
	PRICE DIF[l_dbase];				// ������ ��� ������

	ifstream fin("Text.txt");
	if (!fin) { cout << " ������ �������� ����� "; return 1; }
	int i = 0;							
	while (!fin.eof()) {				
		if (i >= l_dbase) { cout << " ������� ������� ���� "; return 1; }
		fin.read(DIF[i].Tovar, len_name);
		DIF[i].Tovar[len_name] = '\0';
		fin.seekg(1, ios::cur);			

		fin.read(DIF[i].Magazin, len_shop);
		DIF[i].Magazin[len_shop] = '\0';
		fin.seekg(1, ios::cur);			

		fin.getline(buf, len_cena);		
		DIF[i].Cena = atof(buf);

		i++;
	}

	cout << "�������� ���� ������: \n";
	for (int j = 0; j < l_dbase; j++) {
		cout << DIF[j].Tovar << "\t" << DIF[j].Magazin << "\t" << DIF[j].Cena << endl;
	}
	//////////////////////////////////////////////////////////////////////////////
	cout << endl << endl << "������������� ���� ������: \n";
	for (int i = 0; i < l_dbase; i++) {
		for (int j = 0; j < l_dbase; j++) {
			// ���������� �� �������� ������
			if (strcmp(DIF[i].Tovar, DIF[j].Tovar) < 0) {
				PRICE t = DIF[j];	DIF[j] = DIF[i];	DIF[i] = t;
			}
		}
	}

	for (int j = 0; j < l_dbase; j++) {
		cout << DIF[j].Tovar << "\t" << DIF[j].Magazin << "\t" << DIF[j].Cena << endl;
	}
	//////////////////////////////////////////////////////////////////////////////

	char  name[len_name + 1];	
	name[len_name] = '\0';
	cout << endl;
	while (true) {
		cout << "������� �������� ������ ��� ������� END: ";
		cin >> name;
		OemToChar(name, name);	
		if (strcmp(name, "end") == 0 ||
			strcmp(name, "END") == 0 ||
			strcmp(name, "End") == 0) break;
		bool not_found = true;
		for (int i = 0; i < l_dbase; i++) {
			if (strstr(DIF[i].Tovar, name))   
				if (DIF[i].Tovar[strlen(name)] == ' ') {
					cout << DIF[i].Tovar << "\t" << DIF[i].Magazin << "\t" << DIF[i].Cena << endl;
					not_found = false;
				}
		}
		if (not_found) cout << " ������ ������ ���" << endl;
	}

	fin.close();
	system("pause");
	return 0;
}




