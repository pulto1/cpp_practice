#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

// 获取某年某月的天数
int Date::GetMonthDay(int year, int month)
{
	static int DaysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int Day = DaysArray[month];

	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		Day++;
	}

	return Day;
}

// 全缺省的构造函数
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if(_year < 0
		|| (_month < 0 || _month > 12) 
		|| (_day < 0 || _day > GetMonthDay(year, month)))
	{
		cout << "日期非法" << endl;
	}
}

// 拷贝构造函数
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

// 赋值运算符重载
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}

// 日期+=天数
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return (*this) -= -day;
	}
	_day += day;

	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;
}

// 日期+天数
Date Date::operator+(int day)
{
	Date ret(*this);

	ret += day;
	return ret;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return (*this) += -day;
	}

	_day -= day;
	while (_day < 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

// 日期-天数
Date Date::operator-(int day)
{
	Date ret(*this);

	ret -= day;

	return ret;
}

// 前置++
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date ret(*this);

	*this += 1;

	return ret += 1;
}

// 后置--
Date Date::operator--(int)
{
	Date ret(*this);

	*this -= 1;

	return ret -= 1;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;

	return *this;
}

// >运算符重载
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}

	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}

		else if (_month == d._month)
		{
			if (_day > d._day)
				return true;
		}
	}

	return false;
}

// ==运算符重载
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

// >=运算符重载
bool Date::operator >= (const Date& d)
{
	return *this > d || *this == d;
}

// <运算符重载
bool Date::operator < (const Date& d)
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator <= (const Date& d)
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator != (const Date& d)
{
	return !(*this == d);
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int count = 0;
	while (min < max)
	{
		min++;
		count++;
	}

	return flag * count;
}