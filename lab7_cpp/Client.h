#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "PersData.h"

class Client
{
public:
	Client();
	Client(PersData persdata, int compless, int totalless);
	~Client();

	PersData Getpersdata() const;
	int Getcompless() const;
	int Gettotalless() const;
	void Input();
	std::string Out() const;
	void Settotalless(int totalless);
	static int getClientCounter();
	int GettotallessWithPointer(int* result);
	int& GettotallessWithReference();
	friend std::ostream& operator << (std::ostream& out, const Client& client);
	Client operator +(int value)const
	{
		Client temp;
		temp.persdata = this->persdata;
		temp.compless = this->compless + value;
		temp.totalless = this->totalless;
		return temp;
	}
	Client operator ++(int)
	{
		Client temp(*this);
		compless++;
		clientCounter++;
		return temp;
	}
	Client& operator++()
	{
		++compless;
		return *this;
	}


private:
	PersData persdata;
	int compless;
	int totalless;
	static int clientCounter;

	bool CheckArguments(PersData persdata, int compless, int totalless);
};

bool Client::CheckArguments(PersData persdata, int compless, int totalless) {
	return compless > 0&& totalless>0;
}


Client::Client()
{
	persdata = PersData();
	compless = 0;
	totalless = 0;
	clientCounter++;
}


Client::Client(PersData persdata, int compless, int totalless)
{
	this->persdata = persdata;
	this->compless = compless;
	this->totalless = totalless;
	clientCounter++;
}

Client::~Client()
{
	clientCounter--;
}


PersData Client::Getpersdata() const {
	return persdata;
}

int Client::Getcompless() const {
	return compless;
}

int Client::Gettotalless() const {
	return totalless;
}
void Client::Settotalless(int totalless) {
	this->totalless = totalless;
}

int Client::getClientCounter()
{
	return clientCounter;
}

int Client::GettotallessWithPointer(int* result)
{
	*result = this->totalless;
	return *result;
}

int& Client::GettotallessWithReference()
{
	return totalless;
}


void Client::Input() {
	PersData persdata;
	int compless;
	int totalless;
	std::cout << "\tВвод данных клиента\n";
	persdata.Input();
	std::cout << "Введите кол-во пройденных занятий: ";
	std::cin >> compless;
	std::cout << "Введите кол-во всех занятий: ";
	std::cin >> totalless;
	if (CheckArguments(persdata, compless, totalless)) {
		this->persdata = persdata;
		this->compless = compless;
		this->totalless = totalless;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

std::string Client::Out() const {
	std::string st = "\tИнформация о клиенте\nФИО: "+ this->persdata.Getfio() + "\tКол-во пройденных уроков: " + std::to_string(this->compless) + "\tВсего уроков: " + std::to_string(this->totalless) + "\n\n";
	return st;
	//std::cout << "\tИнформация о клиенте\n";
	//std::cout << "ФИО: " << this->persdata.Getfio() << "\tКол-во пройденных уроков: " << this->compless << "\tВсего уроков: " << this->totalless << "\n\n";
}

std::ostream& operator << (std::ostream& out, const Client& client) {
	out << client.Out();
	return out;
}