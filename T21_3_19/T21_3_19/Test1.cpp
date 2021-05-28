#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

void main()

{

	string s1 = "hello world";

	string s2 = "change world";

	string::iterator it = s1.begin();

	swap(s1, s2);

	while (it != s1.end())

		cout << *it;

	cout << endl;

}

//int main()
//
//{
//
//	string str = "Hello Bit.";
//
//	string::iterator it = str.begin();
//
//	while (it != str.end())
//
//	{
//
//		if (*it != ' ')
//
//			cout << *it;
//
//		else
//
//			str.erase(it);
//
//		it++;
//
//	}
//
//	return 0;
//
//}

//int main(int argc, char* argv[])
//{
//
//	string strText = "How are you?";
//
//	string strSeparator = " ";
//
//	string strResult;
//
//	int size_pos = 0;
//
//	int size_prev_pos = 0;
//
//	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//		size_prev_pos = ++size_pos;
//
//	}
//
//	if (size_prev_pos != strText.size())
//
//	{
//
//		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
//
//		cout << strResult << " ";
//
//	}
//
//	cout << endl;
//
//	return 0;
//
//}