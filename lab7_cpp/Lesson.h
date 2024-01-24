#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "Client.h"
#include "Instructor.h"


template <typename T>
class Lesson
{
public:
	Lesson();
	Lesson(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus,T dopInfo);
	~Lesson();

	Client Getclient() const;
	Instructor Getintstructor() const;
	std::string Getdata() const;
	std::string Gettimes() const;
	int Getpaymentstatus() const;
	void Input();
	void Print() const;
	void Setpaymentstatus(int paymentstatus);
	void setDopInfo(T dopInfo);
	T getDopInfo() const;


private:
	Client client;
	Instructor intstructor;
	std::string data;
	std::string time;
	int paymentstatus;
	T dopInfo{};

	bool CheckArguments(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus);
};

template <typename T>
bool Lesson<T>::CheckArguments(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus) {
	return paymentstatus > 0 && paymentstatus < 3;
}

template <typename T>
Lesson<T>::Lesson()
{
	client = Client();
	intstructor= Instructor();
	data="Не указано";
	time = "Не указано";
	paymentstatus = 0;
	dopInfo = "Не указано";
}

template <typename T>
Lesson<T>::Lesson(Client client, Instructor intstructor, std::string data, std::string time, int paymentstatus,T dopInfo)
{
	this->client = client;
	this->intstructor = intstructor;
	this->data = data;
	this->time = time;
	this->paymentstatus = paymentstatus;
	this->dopInfo = dopInfo;
}
template <typename T>
Lesson<T>::~Lesson()
{
}

template <typename T>
Client Lesson<T>::Getclient() const {
	return client;
}

template <typename T>
Instructor Lesson<T>::Getintstructor() const {
	return intstructor;
}

template <typename T>
std::string Lesson<T>::Getdata() const {
	return data;
}

template <typename T>
std::string Lesson<T>::Gettimes() const {
	return time;
}

template <typename T>
int Lesson<T>::Getpaymentstatus() const {
	return paymentstatus;
}

template <typename T>
void Lesson<T>::Setpaymentstatus(int paymentstatus) {
	this->paymentstatus = paymentstatus;
}

template <typename T>
void Lesson<T>::setDopInfo(T dopInfo)
{
	this->dopInfo = dopInfo;
}

template <typename T>
T Lesson<T>::getDopInfo() const {
	return dopInfo;
}

template <typename T>
void Lesson<T>::Input() {
	Client client;
	Instructor intstructor;
	std::string data;
	std::string time;
	int paymentstatus;
	std::cout << "\tВвод данных об уроке\n";
	client.Input();
	intstructor.Input();
	std::cout << "Введите дату: ";
	while (getchar() != '\n');
	std::getline(std::cin, data);
	std::cout << "Введите время: ";
	std::getline(std::cin, time);
	std::cout << "Введите статус оплаты(1-оплачено, 2- не оплачено): ";
	std::cin >> paymentstatus;
	if (CheckArguments(client, intstructor, data, time, paymentstatus)) {
		this->client = client;
		this->intstructor = intstructor;
		this->data = data;
		this->time = time;
		this->paymentstatus = paymentstatus;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

template <typename T>
void Lesson<T>::Print() const {
	std::cout << "\tИнформация об уроке\n";
	std::cout <<"Дата: " << this->data << "\tВремя: " << this->time<<"\tCтатус оплаты(1-оплачено, 2- не оплачено): " << this->paymentstatus << "\n\n";
}
