#define _CRT_SECURE_NO_WARNINGS

#include "string.h"

int main()
{
	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);
	for (auto e : v)
	{
		cout << e << " ";
	}

	/*leo::string s1 = "hello";
	cin >> s1;
	cout << s1 << endl;*/
	/*s1.erase(2, 2);
	cout << s1 << endl;*/
	/*s1.insert(0, 'x');
	s1.insert(0, "suo");*/
	/*cout << s1.find('o') <<endl;
	cout << s1.find("sl") << endl;
	cout << s1.find("ll") << endl;*/
	/*s1[2] = 'r';
	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i];
	}

	cout << endl;*/

	/*s1.resize(10, 'x');
	s1.resize(2);*/


	/*s1.reserve(100);*/

	/*leo::string s2 = "oh";*/
	/*s1.swap(s2);*/
	/*s1.clear();*/
	/*s1 += " wpppp";
	s1 += " wpppp";
	s1 += " wpppp";*/
	//s1.append(" father");
	//s1.append(" father");
	//s1.append(" father");
	//s1.append(" mother");
	/*s1.push_back('x');
	s1.push_back('x');
	s1.push_back('x');
	s1.push_back('x');
	s1 += 't';
	s1 += 't';
	s1 += 't';
	s1 += 't';
	s1 += 't';*/
	/*leo::string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}

	cout << endl;*/

	/*leo::string s2;
	leo::string s3(s1);
	s2 = s1;*/
	return 0;
}