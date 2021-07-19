#include "List.h"

void TestList1()
{
	bit::list<int> l1;
	bit::list<int> l2(5, 3);

	for (auto e : l2)
	{
		cout << e << " ";
	}
	cout << endl;

	bit::list<int> l3(l2);
	for (auto e : l2)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << l2.size() << endl;
	cout << l2.front() << endl;
}

int main()
{
	TestList1();
	return 0;
}