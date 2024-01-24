#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <windows.h>  
#include "Lesson.h"
#include "CarDetailsStorage.h"
#include "Engine.h"
#include "Transmission.h"
#include "Tires.h"
using namespace std;

int Client::clientCounter = 0;
int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	CarDetailsList list = CarDetailsList();
	list.addDetail(new Engine("25.03.2021", "Korea", 80, 2, "Kia", "Rio", 1, "T345EC"));
	list.addDetail(new Transmission("20.10.2019", "Korea", 5, 13, "Renault", "Logan", 1, "X234YY"));
	list.addDetail(new Tires("12.05.2020", "Korea", 15, 65, "Kia", "Rio", 1, "T345EC"));
	list.addDetail(new Engine("25.03.2021", "Korea", 80, 2, "Hyundai", "Solaris", 2, "E856TX"));
	list.addDetail(new Engine("25.03.2021", "Korea", 80, 2, "Mitsubishi", "Lancer", 1, "Y642EA"));
	list.addDetail(new Transmission("25.03.2021", "Korea", 6,12, "Mitsubishi", "Lancer", 1, "Y642EA"));
	cout << "Вывод изначальной таблицы" << endl;
	list.print();
	cout << std::endl;

	list.sortByDetailName();
	cout << "Вывод таблицы после сортировки по имени детали" << endl;
	list.print();
	cout << std::endl;
	list.removeDetail("Engine");
	list.sortByModel();
	cout << "Вывод таблицы после удаления детали: \"Engine\" и сортировки по модели машины" << endl;
	list.print();
	cout << endl;
	cout << "Вывод таблицы после удаления последней детали" << endl;
	list.removeLastDetail();
	list.print();

	cout << "Поиск детали: \"Wheels\"" << endl;
	CarDetail* searchbleDetail;
	try
	{
		searchbleDetail = list.getDetail("Wheels");
	}
	catch (const std::exception&)
	{
		cout << "Деталь не найденна!" << endl;
	}
	cout << "Поиск детали: \"Tires\"" << endl;
	searchbleDetail = list.getDetail("Tires");
	cout << "\tНайденная деталь: " <<endl<< searchbleDetail->Out() << endl;
	
}