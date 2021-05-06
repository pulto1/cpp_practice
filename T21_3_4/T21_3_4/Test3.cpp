#define _CRT_SECURE_NO_WARNINGS

//根据输入的日期，计算是这一年的第几天。。
//
//测试用例有多组，注意循环输入

#include <iostream>

using namespace std;

class Date
{
    friend int main();
public:
    Date(int year, int month, int day)
        :_year(year)
        , _month(month)
        , _day(day)
    {}

    // 获取某年某月的天数
    static int GetMonthDay(int year, int month)
    {
        static int DaysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int Day = DaysArray[month];

        if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            Day++;
        }

        return Day;
    }

    // 日期+=天数
    Date& operator+=(int day)
    {
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

    bool operator!=(const Date& d)
    {
        return !(_year == d._year
            && _month == d._month
            && _day == d._day);
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int year;
    int month;
    int day;

    while (cin >> year >> month >> day)
    {
        if ((month < 1 || month > 12) || day > Date::GetMonthDay(year, month))
        {
            cout << -1 << endl;
        }

        else
        {
            Date d1(year, month, day);
            Date d2(year, 1, 1);
            int days = 1;
            while (d1 != d2)
            {
                d2 += 1;
                days++;
            }

            cout << days << endl;
        }
    }
    return 0;
}