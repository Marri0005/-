#include <iostream>
#include <string>
using namespace std;
// Базовый класс для публикаций
class Publication {
protected:
	string title;
	float price;
public:
	void getdata() {
		cout << "Введите название публикации: ";
		getline(cin, title);
		cout << "Введите цену публикации: ";
		cin >> price;
		cin.ignore(); // Очистка буфера ввода
	}
		void putdata() {
		cout << "Название публикации: " << title << endl;
		cout << "Цена публикации: " << price << endl;
	}
};
// Класс для книг
class Book : public Publication {
protected:
	int pages;
	float sales[3]; // Массив для продаж за 3 месяца
public:
	void getdata() {
		Publication::getdata(); // Вызов getdata() от базового класса
		cout << "Введите количество страниц книги: ";
		cin >> pages;
		cin.ignore();
		cout << "Введите продажи за 3 месяца (разделенные пробелами): ";
		for (int i = 0; i < 3; ++i) {
			cin >> sales[i];
		}
		cin.ignore();
	}
	void putdata() {
		Publication::putdata(); // Вызов putdata() от базового класса
		cout << "Количество страниц: " << pages << endl;
		cout << "Продажи за 3 месяца: ";
		for (int i = 0; i < 3; ++i) {
			cout << sales[i] << " ";
		}
		cout << endl;
	}
};
// Класс для аудиозаписей
class Type : public Publication {
protected:
	int recordingTime;
	float sales[3]; // Массив для продаж за 3 месяца
public:
	void getdata() {
		Publication::getdata(); // Вызов getdata() от базового класса
		cout << "Введите время записи (в минутах): ";
		cin >> recordingTime;
		cin.ignore();
		cout << "Введите продажи за 3 месяца (разделенные пробелами): ";
		for (int i = 0; i < 3; ++i) {
			cin >> sales[i];
		}
		cin.ignore();
	}
	void putdata() {
		Publication::putdata(); // Вызов putdata() от базового класса
		cout << "Время записи: " << recordingTime << " минут" << endl;
		cout << "Продажи за 3 месяца: ";
		for (int i = 0; i < 3; ++i) {
			cout << sales[i] << " ";
		}
			cout << endl;
	}
};
int main() {
	Book book1;
	Type type1;
	cout << "Ввод данных о книге:" << endl;
	book1.getdata();
	cout << "Ввод данных об аудиозаписи:" << endl;
	type1.getdata();
	cout << "Информация о книге:" << endl;
	book1.putdata();
	cout << "Информация об аудиозаписи:" << endl;
	type1.putdata();
	return 0;
}