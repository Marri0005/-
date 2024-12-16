///////////////////ЗАДАНИЕ 1
#include <iostream>
using namespace std;
int main() {
	// Определяем массив из 10 элементов типа short
	short arr[10];
	// Заполняем массив
	cout << "Введите 10 чисел типа short: " << endl;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	// Выводим содержимое массива
	cout << "Массив: ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	// Выводим адрес начала массива
	cout << "Адрес начала массива: " << (long)&arr[0] << endl;
	// Выводим расстояние каждого элемента от начала массива
	for (int i = 0; i < 10; i++) {
		cout << "Элемент " << i << " находится на расстоянии "
			<< (long)&arr[i] - (long)&arr[0] << " байт от начала массива." << endl;
	}
	return 0;
}/////////////////////ЗАДАНИЕ 2(А)#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Класс для представления книги
class Book {
public:
	enum Type { FICTION, NONFICTION };
	// Конструктор
	Book(const string& author, const string& title, Type type) :
		author(author), title(title), type(type) {
		if (author.empty() || title.empty()) {
			throw invalid_argument("Книга не может быть безымянной или без названия.");
		}
	}
	// Получение автора книги
	string getAuthor() const {
		return author;
	}
	// Получение названия книги
	string getTitle() const {
		return title;
	}
	// Получение типа книги
	Type getType() const {
		return type;
	}
private:
	string author;
	string title;
	Type type;
};
// Класс для представления библиотеки
class Library {
public:
	// Добавление книги в библиотеку
	void addBook(const Book& book) {
		books.push_back(book);
	}
	// Вывод содержимого библиотеки
	void printBooks() const {
		cout << "Библиотека содержит следующие книги:" << endl;
		for (const Book& book : books) {
			cout << "Автор: " << book.getAuthor() << endl;
			cout << "Название: " << book.getTitle() << endl;
			cout << "Тип: " << (book.getType() == Book::FICTION ? "Художественная" :
				"Техническая") << endl;
			cout << endl;
		}
	}
private:
	vector<Book> books;
};
int main() {
	try {
		Library library;
		// Наполнение библиотеки книгами
		library.addBook(Book("Булгаков М.А.", "Мастер и Маргарита", Book::FICTION));
		library.addBook(Book("М.Ю. Лермонтов", "Герой нашего времени", Book::FICTION));
		library.addBook(Book("Ф.М. Достоевский", "Преступление и наказание",
			Book::FICTION));
		library.addBook(Book("А. Левенчук", "Системное мышление", Book::NONFICTION));
			library.addBook(Book("Т. Демарк", "Основы технического анализа",
				Book::NONFICTION));
		// Вывод содержимого библиотеки
		library.printBooks();
	}
	catch (const invalid_argument& e) {
		cerr << "Ошибка: " << e.what() << endl;
	}
	return 0;
}



////////////////ЗАДАНИЕ 2(Б)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Класс для представления книги
class Book {
public:
	enum Type { FICTION, NONFICTION };
	// Конструктор
	Book(const string& author, const string& title, Type type) :
		author(author), title(title), type(type) {
		if (author.empty() || title.empty()) {
			throw invalid_argument("Книга не может быть безымянной или без названия.");
		}
	}
	// Получение автора книги
	string getAuthor() const {
		return author;
	}
	// Получение названия книги
	string getTitle() const {
		return title;
	}
	// Получение типа книги
	Type getType() const {
		return type;
	}
private:
	string author;
	string title;
	Type type;
};
// Класс для представления библиотеки
class Library {
public:
	// Добавление книги в библиотеку
	void addBook(const Book& book) {
		books.push_back(book);
	}
	// Вывод количества художественных и технических книг
	void printBookCount() const {
			int fictionCount = 0;
		int nonfictionCount = 0;
		for (const Book& book : books) {
			switch (book.getType()) {
			case Book::FICTION:
				fictionCount++;
				break;
			case Book::NONFICTION:
				nonfictionCount++;
				break;
			}
		}
		cout << "Количество художественной литературы: " << fictionCount << endl;
		cout << "Количество технической литературы: " << nonfictionCount << endl;
	}
private:
	vector<Book> books;
};
int main() {
	try {
		Library library;
		// Наполнение библиотеки книгами
		library.addBook(Book("Булгаков М.А.", "Мастер и Маргарита", Book::FICTION));
		library.addBook(Book("М.Ю. Лермонтов", "Герой нашего времени", Book::FICTION));
		library.addBook(Book("Ф.М. Достоевский", "Преступление и наказание",
			Book::FICTION));
		library.addBook(Book("А. Левенчук", "Системное мышление", Book::NONFICTION));
		library.addBook(Book("Т. Демарк", "Основы технического анализа",
			Book::NONFICTION));
		// Вывод количества книг
		library.printBookCount();
	}
	catch (const invalid_argument& e) {
		cerr << "Ошибка: " << e.what() << endl;
	}
	return 0;
}