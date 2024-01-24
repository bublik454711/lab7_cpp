#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>

class ID
{
public:
	ID();
	ID(int seria, int number);
	~ID();

	int Getseria() const;
	int Getnumber() const;
	void Input();


private:
	int seria;
	int number;

	bool CheckArguments(int seria, int number);
};


bool ID::CheckArguments(int seria, int number) {
	return number > 0 && seria > 0;
}

ID::ID()
{
	number = seria = 0;
}


ID::ID(int seria, int number)
{
	if (CheckArguments(number, seria)) {
		this->number = number;
		this->seria = seria;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

ID::~ID()
{
}


int ID::Getnumber() const {
	return number;
}

int ID::Getseria() const {
	return seria;
}

void ID::Input() {
	int number;
	int seria;

	std::cout << "Введите серию паспорта: ";
	std::cin >> seria;
	std::cout << "Введите номер паспорта: ";
	std::cin >> number;
	while (getchar() != '\n');
	if (CheckArguments(seria, number)) {
		this->number = number;
		this->seria = seria;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}