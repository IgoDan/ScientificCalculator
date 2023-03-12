#pragma once
#include <string>

class Operations
{
public:
	std::string input;
	std::string temp;

	std::string tab_temp[100];

	std::string dzialanie[100];

	std::string znak[100];

	double liczba[100];

	double a = 0;
	double b = 0;
	double wynik = 0;

	int id_liczb = 0;
	int id_znakow = 0;

	double dodawanie();
	double odejmowanie();
	double mnozenie();
	double dzielenie();
	double pierwiastek();
	double potega();
	double procent();
};