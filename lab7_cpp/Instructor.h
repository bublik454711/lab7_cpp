#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Auto.h"
#include "PersData.h"

class Instructor
{
public:
	Instructor();
	Instructor(Auto autO, PersData persdata, int driveExp);
	~Instructor();

	Auto Getauto() const;
	PersData Getpersdata() const;
	int GetdriveExp() const;
	void Input();


private:
	Auto autO;
	PersData persdata;
	int driveExp;

	bool CheckArguments(Auto autO, PersData persdata, int driveExp);
};

bool Instructor::CheckArguments(Auto autO, PersData persdata, int driveExp) {
	return driveExp > 0;
}


Instructor::Instructor()
{
	autO = Auto();
	persdata = PersData();
	driveExp = 0;
}


Instructor::Instructor(Auto autO, PersData persdata, int driveExp)
{
	this->autO = autO;
	this->persdata = persdata;
	this->driveExp = driveExp;
}

Instructor::~Instructor()
{
}


Auto Instructor::Getauto() const {
	return autO;
}

PersData Instructor::Getpersdata() const {
	return persdata;
}

int Instructor::GetdriveExp() const {
	return driveExp;
}


void Instructor::Input() {
	Auto autO;
	PersData persdata;
	int driveExp;
	std::cout << "\tВвод данных инструктора\n";
	autO.Input();
	persdata.Input();
	std::cout << "Введите опыт вождения: ";
	std::cin >> driveExp;
	if (CheckArguments(autO,persdata,driveExp)) {
		this->autO = autO;
		this->persdata = persdata;
		this->driveExp = driveExp;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}