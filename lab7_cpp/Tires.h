#pragma once
#include <iostream>
#include "CarDetail.h"

class Tires :public CarDetail
{
public:
	Tires();
	Tires(std::string installDate, std::string prodСountry, float radius, float width, std::string brand, std::string model, int typeTrans, std::string gosNumber);
	std::string getDetailName() const override;
	~Tires();
	void Input() override;
	std::string Out() const override;
	using CarDetail::operator=;
	friend std::ostream& operator << (std::ostream& out, const Tires& tires);


private:
	float radius;
	float width;

};

std::string Tires::getDetailName() const {
	return "Tires";
}

Tires::Tires()
{
	Auto car;
	this->brand = car.Getbrand();
	this->model = car.Getmodel();
	this->typeTrans = car.GettypeTrans();
	this->gosNumber = car.GetgosNumber();
	this->radius = 0;
	this->width = 0;
	this->installDate = "Не указано";
	this->prodСountry = "Не указано";
}

Tires::Tires(std::string installDate, std::string prodСountry, float radius, float width, std::string brand, std::string model, int typeTrans, std::string gosNumber)
{
	Auto car = Auto(brand, model, typeTrans, gosNumber);
	this->brand = car.Getbrand();
	this->model = car.Getmodel();
	this->typeTrans = car.GettypeTrans();
	this->gosNumber = car.GetgosNumber();
	this->radius = radius;
	this->width = width;
	this->installDate = installDate;
	this->prodСountry = prodСountry;
}

Tires::~Tires()
{
}

void Tires::Input() {
	float radius;
	float width;
	std::string installDate;
	std::string prodСountry;
	Auto::Input();
	std::cout << "\tВвод данных шин\n";
	std::cout << "Введите радиус: ";
	std::cin >> radius;
	std::cout << "Введите ширину: ";
	std::cin >> width;
	std::cout << "Введите дату установки: ";
	std::cin >> installDate;
	while (getchar() != '\n');
	std::cout << "Введите страну производителя: ";
	std::getline(std::cin, prodСountry);
	this->radius = radius;
	this->width = width;
	this->installDate = installDate;
	this->prodСountry = prodСountry;
}




std::string Tires::Out() const {
	std::string st = "\tИнформация о детали\nМодель машины: " + this->Getmodel() + "\tСтрана производитель: " + this->prodСountry + "\tРадиус: " + std::to_string(this->radius) + "\tШирина: " + std::to_string(this->width) + "\n\n";
	return st;
}

std::ostream& operator << (std::ostream& out, const Tires& tires) {
	out << tires.Out();
	return out;
}