//#define _CRT_SECURE_NO_WARNINGS
//
////���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//    friend int main();
//public:
//    Date(int year, int month, int day)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//
//    // ��ȡĳ��ĳ�µ�����
//    int GetMonthDay(int year, int month)
//    {
//        static int DaysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        int Day = DaysArray[month];
//
//        if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//        {
//            Day++;
//        }
//
//        return Day;
//    }
//
//    // ����+=����
//    Date& operator+=(int day)
//    {
//        _day += day;
//
//        while (_day > GetMonthDay(_year, _month))
//        {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//
//            if (_month == 13)
//            {
//                _month = 1;
//                _year++;
//            }
//        }
//
//        return *this;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    int m;
//    int year;
//    int month;
//    int day;
//    int n;
//
//    cin >> m;
//    while (m--)
//    {
//        cin >> year >> month >> day >> n;
//        Date d1(year, month, day);
//        d1 += n;
//        printf("%04d-%02d-%02d\n", d1._year, d1._month, d1._day);
//    }
//
//    return 0;
//}