#include "vector.h"

void TestVector1()
{
	bit::vector<int> v1;
	bit::vector<int> v2(10, 3);
	/*for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;*/

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bit::vector<int> v3(arr, arr + 10);
	/*for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;*/

	bit::vector<int> v4(v3);
	for (auto e : v4)
	{
		cout << e << " ";
	}
	cout << endl;

	bit::vector<int> v5;
	v5 = v2;
	for (auto e : v5)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector2()
{
	int arr[] = { 1, 2, 3, 4};
	bit::vector<int> v3(arr, arr + 4);
	
	v3.reserve(10);
	cout << v3.capacity() << endl;
	
	v3.resize(3);
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
	
	v3.resize(15, 5);
	for (auto e : v3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void TestVector3()
{
	bit::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	bit::vector<string> v2;
	v2.push_back("111");
	v2.push_back("222");
	v2.push_back("433");
	v2.push_back("444");
	v2.push_back("555");
	for (auto e : v2)
	{
		cout << e << " ";
	}
	cout << endl;

}

int main()
{

	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };

	int n = sizeof(ar) / sizeof(int);

	bit::vector<int> v(ar, ar + n);

	bit::vector<int>::iterator it = v.begin();

	while (it != v.end())

	{

		if (*it != 0)

			cout << *it;

		else

			v.erase(it);

		it++;

	}

	return 0;

}