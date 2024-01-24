#pragma once
#include <iostream>
#include "CarDetail.h"

class Transmission :public CarDetail
{
public:
	Transmission();
	Transmission(std::string installDate, std::string prodСountry, int gears, float transRatio, std::string brand, std::string model, int typeTrans, std::string gosNumber);
	std::string getDetailName() const override;
	~Transmission();
	void Input() override;
	std::string Out() const override;
	using CarDetail::operator=;
	friend std::ostream& operator << (std::ostream& out, const Transmission& trans);


private:
	int gears;
	float transRatio;

};

std::string Transmission::getDetailName() const {
	return "Transmission";
}

Transmission::Transmission()
{
	Auto car;
	this->brand = car.Getbrand();
	this->model = car.Getmodel();
	this->typeTrans = car.GettypeTrans();
	this->gosNumber = car.GetgosNumber();
	this->gears = 0;
	this->transRatio = 0;
	this->installDate = "Не указано";
	this->prodСountry = "Не указано";
}

Transmission::Transmission(std::string installDate, std::string prodСountry, int gears, float transRatio, std::string brand, std::string model, int typeTrans, std::string gosNumber)
{
	Auto car = Auto(brand, model, typeTrans, gosNumber);
	this->brand = car.Getbrand();
	this->model = car.Getmodel();
	this->typeTrans = car.GettypeTrans();
	this->gosNumber = car.GetgosNumber();
	this->gears = gears;
	this->transRatio = transRatio;
	this->installDate = installDate;
	this->prodСountry = prodСountry;
}

Transmission::~Transmission()
{
}

void Transmission::Input() {
	int gears;
	float transRatio;
	std::string installDate;
	std::string prodСountry;
	Auto::Input();
	std::cout << "\tВвод данных КПП\n";
	std::cout << "Введите кол-во передач: ";
	std::cin >> gears;
	std::cout << "Введите передаточное число: ";
	std::cin >> transRatio;
	std::cout << "Введите дату установки: ";
	std::cin >> installDate;
	while (getchar() != '\n');
	std::cout << "Введите страну производителя: ";
	std::getline(std::cin, prodСountry);
	this->gears = gears;
	this->transRatio = transRatio;
	this->installDate = installDate;
	this->prodСountry = prodСountry;
}




std::string Transmission::Out() const {
	std::string st = "\tИнформация о детали\nМодель машины: " + this->Getmodel() + "\tСтрана производитель: " + this->prodСountry + "\tКол-во передач: " + std::to_string(this->gears) + "\tПередаточное число: " + std::to_string(this->transRatio) + "\n\n";
	return st;
}

std::ostream& operator << (std::ostream& out, const Transmission& trans) {
	out << trans.Out();
	return out;
}