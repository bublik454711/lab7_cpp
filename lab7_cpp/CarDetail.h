#pragma once
#include <iostream>
#include "Auto.h"

class CarDetail abstract: public Auto
{
public:
	virtual std::string getDetailName() const abstract = 0;
	virtual void Input() abstract = 0;
	virtual std::string Out() const abstract = 0;
	void operator=(Auto& car)
	{
		this->brand = car.Getbrand();
		this->model = car.Getmodel();
		this->gosNumber = car.GetgosNumber();
		this->typeTrans = car.GettypeTrans();
	}
protected:
	std::string installDate = "Не указано";
	std::string prodСountry = "Не указано";
};


