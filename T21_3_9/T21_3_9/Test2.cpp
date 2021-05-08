#define _CRT_SECURE_NO_WARNINGS

//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;

		if (!(year >= 0 &&
			month > 0 && month < 13 &&
			day > 0 && day <= GetMonthDay(year, month)))
		{
			cout << "日期非法" << endl;
		}
	}

	int GetMonthDay(int year, int month)
	{
		static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int days = daysArray[month];
		if (month == 2 &&
			((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			days = 29;
		}

		return days;
	}

	Date& operator += (int day)
	{
		_day += day;
		// 日期是否合法
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}

		return *this;
	}

	bool operator!=(const Date& d)
	{
		return !(_year == d._year
			&& _month == d._month
			&& _day == d._day);
	}

	int operator-(const Date& d)
	{
		// 之间进行日期之间相减，不好操作
		Date max = *this, min = d;

		int n = 0;
		while (min != max)
		{
			n += 1;
			min += 1;
		}

		return n + 1;
	}

private:
	int _year;
	int _month;
	int _day;

};

int main()
{
	int n1 = 0;
	int n2 = 0;

	while (cin >> n1 >> n2)
	{
		int year1, month1, day1 = 0;
		int year2, month2, day2 = 0;

		year1 = n1 / 10000;
		month1 = n1 % 10000 / 100;
		day1 = n1 % 100;
		year2 = n2 / 10000;
		month2 = n2 % 10000 / 100;
		day2 = n2 % 100;

		Date d1(year1, month1, day1);
		Date d2(year2, month2, day2);

		cout << d2 - d1 << endl;
	}

	return 0;
}