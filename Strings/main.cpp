#include<iostream>
#include<Windows.h>
using namespace std;
int StringLenght(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	'\0';
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	/*char str[] = "Hello";
	cout << str << endl;*/

	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер введенной строки: " << StringLenght(str) << endl;
}
int StringLenght(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}