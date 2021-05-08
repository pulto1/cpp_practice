#define _CRT_SECURE_NO_WARNINGS

//给出年分m和一年中的第n天，算出第n天是几月几号。

#include <iostream>

using namespace std;

int main()
{
    int commonDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    int leapDays[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };

    int y = 0;
    int n = 0;
    int m = 0;
    int d = 0;

    while (cin >> y >> n)
    {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        {
            int i = 1;
            while (1)
            {
                if (n <= leapDays[i])
                {
                    m = i;
                    d = n - leapDays[i - 1];
                    break;
                }

                else
                {
                    i++;
                }
            }
        }

        else
        {
            int i = 1;
            while (1)
            {
                if (n <= commonDays[i])
                {
                    m = i;
                    d = n - commonDays[i - 1];
                    break;
                }

                else
                {
                    i++;
                }
            }
        }

        printf("%d-%02d-%02d\n", y, m, d);
    }

    return 0;
}