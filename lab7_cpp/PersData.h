#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Docs.h"

class PersData
{
public:
	PersData();
	PersData(Docs docs, int age, std::string fio);
	~PersData();

	Docs Getdocs() const;
	int Getage() const;
	std::string Getfio() const;
	void Input();


private:
	Docs docs;
	int age;
	std::string fio;

	bool CheckArguments(Docs docs, int age, std::string fio);
};

bool PersData::CheckArguments(Docs docs, int age, std::string fio) {
	return age > 0;
}


PersData::PersData()
{
	docs=Docs();
	age=0;
	fio = "Не указано";
}


PersData::PersData(Docs docs, int age, std::string fio)
{
	this->docs = docs;
	this->age = age;
	this->fio = fio;
}

PersData::~PersData()
{
}


Docs PersData::Getdocs() const {
	return docs;
}

int PersData::Getage() const {
	return age;
}

std::string PersData::Getfio() const {
	return fio;
}


void PersData::Input() {
	Docs docs;
	int age;
	std::string fio;
	std::cout << "\tВвод персональных данных\n";
	docs.Input();
	std::cout << "Введите Возраст: ";
	std::cin >> age;
	std::cout << "Введите ФИО: ";
	while (getchar() != '\n');
	std::getline(std::cin, fio);
	if (CheckArguments(docs, age,fio)) {
		this->docs = docs;
		this->age = age;
		this->fio = fio;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}