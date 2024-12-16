///////////////////������� 1
#include <iostream>
using namespace std;
int main() {
	// ���������� ������ �� 10 ��������� ���� short
	short arr[10];
	// ��������� ������
	cout << "������� 10 ����� ���� short: " << endl;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	// ������� ���������� �������
	cout << "������: ";
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	// ������� ����� ������ �������
	cout << "����� ������ �������: " << (long)&arr[0] << endl;
	// ������� ���������� ������� �������� �� ������ �������
	for (int i = 0; i < 10; i++) {
		cout << "������� " << i << " ��������� �� ���������� "
			<< (long)&arr[i] - (long)&arr[0] << " ���� �� ������ �������." << endl;
	}
	return 0;
}/////////////////////������� 2(�)#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ����� ��� ������������� �����
class Book {
public:
	enum Type { FICTION, NONFICTION };
	// �����������
	Book(const string& author, const string& title, Type type) :
		author(author), title(title), type(type) {
		if (author.empty() || title.empty()) {
			throw invalid_argument("����� �� ����� ���� ���������� ��� ��� ��������.");
		}
	}
	// ��������� ������ �����
	string getAuthor() const {
		return author;
	}
	// ��������� �������� �����
	string getTitle() const {
		return title;
	}
	// ��������� ���� �����
	Type getType() const {
		return type;
	}
private:
	string author;
	string title;
	Type type;
};
// ����� ��� ������������� ����������
class Library {
public:
	// ���������� ����� � ����������
	void addBook(const Book& book) {
		books.push_back(book);
	}
	// ����� ����������� ����������
	void printBooks() const {
		cout << "���������� �������� ��������� �����:" << endl;
		for (const Book& book : books) {
			cout << "�����: " << book.getAuthor() << endl;
			cout << "��������: " << book.getTitle() << endl;
			cout << "���: " << (book.getType() == Book::FICTION ? "��������������" :
				"�����������") << endl;
			cout << endl;
		}
	}
private:
	vector<Book> books;
};
int main() {
	try {
		Library library;
		// ���������� ���������� �������
		library.addBook(Book("�������� �.�.", "������ � ���������", Book::FICTION));
		library.addBook(Book("�.�. ���������", "����� ������ �������", Book::FICTION));
		library.addBook(Book("�.�. �����������", "������������ � ���������",
			Book::FICTION));
		library.addBook(Book("�. ��������", "��������� ��������", Book::NONFICTION));
			library.addBook(Book("�. ������", "������ ������������ �������",
				Book::NONFICTION));
		// ����� ����������� ����������
		library.printBooks();
	}
	catch (const invalid_argument& e) {
		cerr << "������: " << e.what() << endl;
	}
	return 0;
}



////////////////������� 2(�)
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ����� ��� ������������� �����
class Book {
public:
	enum Type { FICTION, NONFICTION };
	// �����������
	Book(const string& author, const string& title, Type type) :
		author(author), title(title), type(type) {
		if (author.empty() || title.empty()) {
			throw invalid_argument("����� �� ����� ���� ���������� ��� ��� ��������.");
		}
	}
	// ��������� ������ �����
	string getAuthor() const {
		return author;
	}
	// ��������� �������� �����
	string getTitle() const {
		return title;
	}
	// ��������� ���� �����
	Type getType() const {
		return type;
	}
private:
	string author;
	string title;
	Type type;
};
// ����� ��� ������������� ����������
class Library {
public:
	// ���������� ����� � ����������
	void addBook(const Book& book) {
		books.push_back(book);
	}
	// ����� ���������� �������������� � ����������� ����
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
		cout << "���������� �������������� ����������: " << fictionCount << endl;
		cout << "���������� ����������� ����������: " << nonfictionCount << endl;
	}
private:
	vector<Book> books;
};
int main() {
	try {
		Library library;
		// ���������� ���������� �������
		library.addBook(Book("�������� �.�.", "������ � ���������", Book::FICTION));
		library.addBook(Book("�.�. ���������", "����� ������ �������", Book::FICTION));
		library.addBook(Book("�.�. �����������", "������������ � ���������",
			Book::FICTION));
		library.addBook(Book("�. ��������", "��������� ��������", Book::NONFICTION));
		library.addBook(Book("�. ������", "������ ������������ �������",
			Book::NONFICTION));
		// ����� ���������� ����
		library.printBookCount();
	}
	catch (const invalid_argument& e) {
		cerr << "������: " << e.what() << endl;
	}
	return 0;
}