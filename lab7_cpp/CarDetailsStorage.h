#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "CarDetail.h"

class CarDetailsList
{
public:
	CarDetailsList() = default;
	CarDetailsList(std::vector<CarDetail*> details);
	~CarDetailsList() = default;

	void addDetail(CarDetail* detail);
	void removeDetail(std::string detailName);
	void removeLastDetail();
	CarDetail* getDetail(std::string detailName);
	void sortByDetailName();
	void sortByModel();
	void print();
private:
	std::vector<CarDetail*> details;

};

CarDetailsList::CarDetailsList(std::vector<CarDetail*> details)
{
	this->details = details;
}

void CarDetailsList::addDetail(CarDetail* detail)
{
	details.push_back(detail);
}

void CarDetailsList::removeDetail(std::string detailName)
{
	//создаем итератор, который будет указывать либо на нужный элемент, либо на конец вектора, если элемента не окажется
	auto removable = std::find_if(this->details.begin(), this->details.end(), [&](CarDetail* detail) {
		return detail->getDetailName() == detailName;
		}); //используем лямбда-функцию для поиска конкретной модели

	if (removable != this->details.end()) {
		this->details.erase(removable);
	}
	else {
		throw std::runtime_error("Деталь не найдена!");
	}
}

void CarDetailsList::removeLastDetail()
{
	if (this->details.size() > 0) {
		this->details.pop_back();
	}
	else {
		throw std::runtime_error("Нет деталей!");
	}
}

CarDetail* CarDetailsList::getDetail(std::string detailName)
{
	//используем тот же итератор из removeComponent()
	auto removable = std::find_if(this->details.begin(), this->details.end(), [&](CarDetail* detail) {
		return detail->getDetailName() == detailName;
		});

	if (removable != this->details.end()) {
		return *removable;
	}
	else {
		throw std::runtime_error("Деталь не найдена!");
	}
}

void CarDetailsList::sortByDetailName()
{
	std::sort(this->details.begin(), this->details.end(), [&](CarDetail* first, CarDetail* second) {
		return first->getDetailName() < second->getDetailName();
		});
}

void CarDetailsList::sortByModel()
{
	std::sort(this->details.begin(), this->details.end(), [&](CarDetail* first, CarDetail* second) {
		return first->Getmodel() < second->Getmodel();
		});
}

void CarDetailsList::print()
{
	std::cout 	<< "\tНазвание детали           Модель машины"<< std::endl;

	for (auto detail : this->details) {
		std::cout << std::setw(20)<< detail->getDetailName() <<"\t\t\t" << detail->Getmodel()<<std::endl;
	}
}
