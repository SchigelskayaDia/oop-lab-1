
/*Ученики. Ф.И.О., класс (цифра+буква) предметы, средний балл. Выбор по номеру кл. Класс реализовать с помощью битового поля, предметы через перечисление
Реализовать функции ввода с клавиатуры, вывода на экран, удаления, поиска элементов. */

#include<iostream>
#include <windows.h>
#define size 15
using namespace std;


enum Lessons {
	russian , math
}less;


struct people
{
	char name[20];
	char surname[20];
	int average;
	int pos;
	char letter[10];
};


struct Klass {
	unsigned number : 2;
};


int kol = 0, m[size], exsp;
int choice;
int z;
struct people ch[size];
struct Klass kl[size];
struct people bad;
struct Klass bad1;
int pos;


void input()
{
	if (kol < size)
	{
		cout << "Number " << kol + 1 << endl;
		cout << "Name: ";
		cin >> ch[kol].name;
		cout << "Surname: ";
		cin >> ch[kol].surname;
		cout << "Average score: ";
		cin >> ch[kol].average;
		cout << "Klass number : ";
		cin >> z;
		kl[kol].number = z;
		cout << "Klass letter: ";
		cin >> ch[kol].letter;
		cout << "Lessons: ";
		cin >> ch[kol].pos;
		kol++;
	}	
}


void output() {
	for (int i = 0; i < kol; i++)
	{
		cout << "Name: " << ch[i].name <<endl;
		cout << "Surname: " << ch[i].surname << endl;
		cout << "Average score: " << ch[i].average << endl;
		cout << "Klass number: " << kl[i].number << endl;
		cout << "Klass letter: " << ch[i].letter << endl;
		cout << "Lessons: ";
		if (ch[i].pos == 0) {
			cout << "russian" << endl;
		}
		else {
			cout << "math" << endl;
		}	
	}

}


void findInformation(int number) {
	int p = 0;
	for (int i = 0; i < kol; i++) {
		if (kl[i].number == number)
		{
			cout << "Name: " << ch[i].name << endl;
			cout << "Surname: " <<  ch[i].surname << endl;
			cout << "Average score: " << ch[i].average << endl;
			cout << "Klass number: " << kl[i].number << endl;
			cout << "Klass letter: " << ch[i].letter << endl;
			cout << "Lessons: ";
			if (pos == 1) {
				cout << "russian" << endl;
			}
			if (pos == 2) {
				cout << "math" << endl;
			}
			if (pos == 3) {
				cout << "english" << endl;;
			}
			p++;
		}
	}
}


void deleteElement() {
	int d;
	cout << "Номер удаленного элемента " << endl;
	cin >> d;
	for (int d1 = (d - 1); d1 < kol; d1++)
	{
		ch[d1] = ch[d1 + 1];
	}
	kol = kol - 1;
	}


void main()
{
	setlocale(LC_CTYPE, "Russian");
	while (1) {
		system("cls");
		cout << "1-Ввод информации" << endl;
		cout << "2-Вывод информации" << endl;
		cout << "3-Поиск по классу" << endl;
		cout << "4-Удаление информации" << endl;
		cout << "5-Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			input();
			system("pause");
			break;
		}
		case 2: {
			output();
			system("pause");
			break;
		}
		case 3: {
			int k;
			cin >> k;
			findInformation(k);
			system("pause");
			break;
		}
		case 4: {
			deleteElement();
			system("pause");
			break;
		}
		}
	}
}