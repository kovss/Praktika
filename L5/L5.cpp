#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////// 
	setlocale(LC_ALL, "RUS");
	/////////////////////////////////////////////////////////////////////////////////////////////////////// 
	ifstream fin("Text.txt");
	if (!fin) { cout << "Ошибка чтения .txt файла."; system("pause"); return 1; }
	fin.seekg(0, ios::end);
	long int len = fin.tellg();
	char* buf = new char[len + 1];
	fin.seekg(0, ios::beg);
	fin.read(buf, len);
	buf[len] = '\0';
	/////////////////////////////////////////////////////////////////////////////////////////////////////// 

	int i = 0;
	int k;

	while (buf[i]) { i++; }
	i = i - 2;
	k = i + 1;

	while (i > 0)
	{
		while (buf[i] != '.' && buf[i] != '!' && buf[i] != '?' && i > 0)i--;

		for (int j = i + 1; j <= k; j++)
		{
			cout << buf[j];
		}
		k = i;
		i--;

	}

	cout << endl;


	fin.close();
	system("pause");
	return 0;
}