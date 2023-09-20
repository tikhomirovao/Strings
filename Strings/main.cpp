#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctype.h>
#include<Windows.h>
using namespace std;
int StringLenght(const char str[]);
char* to_upper(char str[]);
char* to_lower(char str[]);

char* shrink(char str[]);
bool is_palindrome(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	cout << 'Ё' - 'ё' << endl;
	'\0';
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	/*char str[] = "Hello";
	cout << str << endl;*/

	const int SIZE = 256;
	char str[SIZE] = "Аргентина манит негра";
	//cout << "Введите строку: ";
	//cin >> str;
	//SetConsoleCP(1251);
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер введенной строки: " << StringLenght(str) << endl;
	//cout << to_upper(str) << endl;
	//cout << to_lower(str) << endl;
	cout << typeid(str).name() << endl;
	cout << shrink(str) << endl;
	cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	cout << str << endl;
}
int StringLenght(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z')str[i] -= 32;
		if(str[i]>='а' && str[i]<='я')str[i] -= 32;
		if (str[i] == 'ё')str[i] -= 16;*/
		str[i] = toupper(str[i]);
	}
	return str;
}char* to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;
		if(str[i]>='А' && str[i]<='Я')str[i] += 32;
		if (str[i] == 'Ё')str[i] += 16;*/
		str[i] = tolower(str[i]);
	}
	return str;
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	while (str[0] == ' ')for (int i = 0; str[i]; i++)str[i] = str[i + 1];
	return str;
}
char* remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)for (int j = i; str[j]; j++)str[j] = str[j + 1];
	}
	return str;
}
bool is_palindrome(const char str[])
{
	cout << typeid(str).name() << endl;
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	n = strlen(buffer);
	for (int i = 0; i<n/2; i++)
	{
		if (buffer[i] != buffer[n - i - 1])
		{
			delete buffer;
			return false;
		}
	}
	delete buffer;
	return true;
}