/////////////////////ЗАДАНИЕ 1
#include <iostream>
#include <vector>
#include <memory>
#include <string>
// Базовый класс Detail
class Detail {
public:
	virtual ~Detail() = default;
	virtual void printInfo() const = 0;
protected:
	Detail() = default;
};
// Производный класс Assembly
class Assembly : public Detail {
public:
	Assembly(const std::string& name, int id) : name_(name), id_(id) {}
	void printInfo() const override {
		std::cout << "Assembly: " << name_ << " (ID: " << id_ << ")" << std::endl;
	}
protected:
	Assembly() = default;
private:
	std::string name_;
	int id_;
};
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
template <typename T>
void addToVector(std::vector<std::unique_ptr<Detail>>& vec, T&& obj) {
	vec.push_back(make_unique<T>(std::forward<T>(obj)));
}
int main() {
	std::vector<std::unique_ptr<Detail>> details;
	// Создание и добавление объектов в вектор
	addToVector(details, Assembly("Engine", 1));
	addToVector(details, Assembly("Wheel", 2));
	addToVector(details, Assembly("Body", 3));
	for (const auto& detail : details) {
		detail->printInfo();
	}
	return 0;
}

//////////////////////ЗАДАНИЕ 2
#include <iostream>
#include <vector>
#include <memory>
#include <random>
class Base {
public:
	virtual void printType() { std::cout << "Base\n"; }
	virtual ~Base() = default;
};
class Derived : public Base {
public:
	void printType() override { std::cout << "Derived\n"; }
};
// Функция для добавления объектов в хранилище
void add(std::shared_ptr<Base> obj, std::vector<std::shared_ptr<Base>>& storage) {
	storage.push_back(obj);
}
int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 10); // Создаем от 1 до 10 объектов
	std::vector<std::shared_ptr<Base>> storage;
	for (int i = 0; i < distrib(gen); ++i) {
		int type = distrib(gen);
		if (type % 2 == 0) {
			add(std::make_shared<Base>(), storage);
		}
		else {
			add(std::make_shared<Derived>(), storage);
		}
	}
	std::cout << "Objects in storage:\n";
	for (const auto& obj : storage) {
		obj->printType();
	}
	storage.clear();
	std::cout << "Resources released.\n";
	return 0;
}
