#ifndef Date_H
#define Date_H
#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date() = default;
	Date(int day, int month, int year);	//constructor
	Date(const Date& other); // copy c'tor

	bool setDay(int day);
	bool setMonth(int month);
	bool setYear(int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	bool checkDay(int day);
	bool checkMonth(int month);
	bool checkYear(int year);

	void setDate(int day, int month, int year);
};

#endif // !Date_H
