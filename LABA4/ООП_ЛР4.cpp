#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>
// Базовый класс для средств передвижения
class Vehicle {
public:
	virtual void print() const = 0;
	virtual ~Vehicle() = default;
};
// Класс Велосипед
class Bicycle : public Vehicle {
public:
	void print() const override {
		std::cout << "Это велосипед." << std::endl;
	}
};
// Класс Автомобиль
class Car : public Vehicle {
public:
	void print() const override {
		std::cout << "Это автомобиль." << std::endl;
	}
};
// Класс Грузовик
class Truck : public Vehicle {
public:
	void print() const override {
		std::cout << "Это грузовик." << std::endl;
	}
};
// Шаблонный класс для хранения массива указателей на объекты произвольного класса
template <typename T>
class Array {
private:
	std::vector<T*> data; // Вектор указателей
public:
	Array(size_t size) {
		data.resize(size);
	}
	T*& operator[](size_t index) {
		if (index >= data.size()) {
			throw std::out_of_range("индекс находится вне диапазона");
		}
		return data[index];
	}
	size_t size() const {
		return data.size();
	}
	~Array() {
		for (T* ptr : data) {
			delete ptr; // Освобождение памяти
		}
	}
};
int main() {
	try {
		Array<Vehicle> vehicles(3);
		vehicles[0] = new Bicycle();
		vehicles[1] = new Car();
		vehicles[2] = new Truck();
		for (size_t i = 0; i < vehicles.size(); ++i) {
			vehicles[i]->print();
		}
		try {
			vehicles[3]->print();
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Обнаружено исключение:" << e.what() << std::endl;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}