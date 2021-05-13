#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
public:
	Date();					   // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int getYear() const;	   // get the year
	int getMonth() const;	   // get the month
	int getDay() const;		   // get the day
	void next();			   // advance to next day

	friend ostream& operator<<(ostream& os, const Date& dt){
		os << dt.year << '-' << dt.month << '-' << dt.day;
		return os;
	}

	friend istream& operator>>(istream& is, Date& dt){

		int d, m, y;   // datumet
		char ch1, ch2; // '-'

		
		is >> y >> ch1 >> m >> ch2 >> d;
		if (ch1 != '-' || ch2 != '-' || m > 12 || d > daysPerMonth[m - 1] || to_string(y).length() !=4){
			is.setstate(ios_base::failbit); //set state of good
		}

		if (!is.fail()){
			dt.year = y;
			dt.month = m;
			dt.day = d;
		}
		return is;
	}

private:
	int year;					 // the year (four digits)
	int month;					 // the month (1-12)
	int day;					 // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month
};

#endif