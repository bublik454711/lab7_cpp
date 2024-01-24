#pragma once
#include <iostream>
#include "CarDetail.h"

class Engine:public CarDetail
{
public:
	Engine();
	Engine(std::string installDate, std::string prodСountry, int horsePower, int capacity, std::string brand, std::string model, int typeTrans, std::string gosNumber);
	std::string getDetailName() const override;
	~Engine();
	void Input() override;
	std::string Out() const override;
	using CarDetail::operator=;
	friend std::ostream& operator << (std::ostream& out, const Engine& eng);


private:
	int horsePower;
	int capacity;

	bool CheckArguments(int horsePower, int capacity);
};

std::string Engine::getDetailName() const {
	return "Engine";
}

Engine::Engine()
{
	Auto car;
	this->brand = car.Getbrand();
	this->model = car.Getmodel();
	this->typeTrans = car.GettypeTrans();
	this->gosNumber = car.GetgosNumber();
	this->horsePower = 0;
	this->capacity = 0;
	this->installDate = "Не указано";
	this->prodСountry = "Не указано";
}

Engine::Engine(std::string installDate, std::string prodСountry, int horsePower, int capacity, std::string brand, std::string model, int typeTrans, std::string gosNumber)
{
	Auto car=Auto(brand,  model, typeTrans, gosNumber);
	this->brand = car.Getbrand();
	this->model = car.Getmodel();
	this->typeTrans = car.GettypeTrans();
	this->gosNumber = car.GetgosNumber();
	this->horsePower = horsePower;
	this->capacity = capacity;
	this->installDate = installDate;
	this->prodСountry = prodСountry;
}

Engine::~Engine()
{
}

void Engine::Input() {
	int horsePower;
	int capacity;
	std::string installDate;
	std::string prodСountry;
	Auto::Input();
	std::cout << "\tВвод данных двигателя\n";
	std::cout << "Введите мощность двигателя в л.с.: ";
	std::cin >> horsePower;
	std::cout << "Введите объем двигателя в л: ";
	std::cin >> capacity;
	std::cout << "Введите дату установки: ";
	std::cin >> installDate;
	while (getchar() != '\n');
	std::cout << "Введите страну производителя: ";
	std::getline(std::cin, prodСountry);
	this->horsePower = horsePower;
	this->capacity = capacity;
	this->installDate = installDate;
	this->prodСountry = prodСountry;
}




std::string Engine::Out() const {
	std::string st = "\tИнформация о детали\nМодель машины: " + this->Getmodel() +"\tСтрана производитель: " + this->prodСountry + "\tМощность: " + std::to_string(this->horsePower) +"\tОбъем: " + std::to_string(this->capacity) +"\n\n";
	return st;
}

std::ostream& operator << (std::ostream& out, const Engine& eng) {
	out << eng.Out();
	return out;
}