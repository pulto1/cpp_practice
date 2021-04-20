#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"

int main()
{
	Date d1;
	Date d2(2021, 2, 3);
	/*d2++;
	
	++d2;
	--d2;
	d2--;*/
	Date d6(2021, 5, 15);
	int ret = d6 - d2;
	int tmp = d2 - d6;

	if (d6 > d2)
	{
		cout << "d6 > d2" << endl;
	}

	d2 = d6 - 1000;
	d6 -= 1000;
	d1 = d2 + 100;
	d2 += 1000;
	Date d3(2021, 2, 29);
	/*d3 = d2;*/
	Date d4(d2);
	
	Date d5(2021, 2, 4);
	d1 = d2 = d5;
	

	return 0;
}