#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>


class Auto
{
public:
	Auto();
	Auto(std::string brand, std::string model, int typeTrans, std::string gosNumber);
	~Auto();

	std::string Getbrand() const;
	std::string Getmodel() const;
	int GettypeTrans() const;
	std::string GetgosNumber() const;
	void Input();


protected:
	std::string brand;
	std::string model;
	int typeTrans;
	std::string gosNumber;

};




Auto::Auto()
{
	brand = "Не указано";
	model = "Не указано";
	typeTrans=0;
	gosNumber = "Не указано";
}


Auto::Auto(std::string brand, std::string model, int typeTrans, std::string gosNumber)
{
	this->brand = brand;
	this->model = model;
	this->typeTrans = typeTrans;
	this->gosNumber = gosNumber;
}

Auto::~Auto()
{
}


std::string Auto::Getbrand() const {
	return brand;
}

std::string Auto::Getmodel() const {
	return model;
}

int Auto::GettypeTrans() const {
	return typeTrans;
}

std::string Auto::GetgosNumber() const {
	return gosNumber;
}

void Auto::Input() {
	std::string brand;
	std::string model;
	int typeTrans;
	std::string gosNumber;
	std::cout << "\tВвод данных авто\n";
	std::cout << "Введите марку машины: ";
	while (getchar() != '\n');
	std::getline(std::cin, brand);
	std::cout << "Введите модель машины: ";
	std::getline(std::cin, model);
	std::cout << "Введите тип трансмиссии(1-механика, 2-автомат): ";
	std::cin >> typeTrans;
	while (getchar() != '\n');
	std::cout << "Введите гос. номер: ";
	std::getline(std::cin, gosNumber);
	this->brand = brand;
	this->model = model;
	this->typeTrans = typeTrans;
	this->gosNumber = gosNumber;
}