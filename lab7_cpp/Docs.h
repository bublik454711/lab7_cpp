#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "SNILS.h"
#include "ID.h"


class Docs
{
public:
	Docs();
	Docs(SNILS snils, ID id);
	~Docs();

	SNILS GetSNILS() const;
	ID GetID() const;
	void Input();


private:
	SNILS snils;
	ID id;

};



Docs::Docs()
{
	snils = SNILS();
	id = ID();
}


Docs::Docs(SNILS snils, ID id)
{
	this->snils = snils;
	this->id = id;
}

Docs::~Docs()
{
}


SNILS Docs::GetSNILS() const {
	return snils;
}

ID Docs::GetID() const {
	return id;
}

void Docs::Input() {
	SNILS snils;
	ID id;
	std::cout << "\tВвод документов\n";
	std::cout << "\tВвод СНИЛСА\n";
	snils.Input();
	std::cout << "\tВвод паспорта\n";
	id.Input();
	this->snils = snils;
	this->id = id;
}