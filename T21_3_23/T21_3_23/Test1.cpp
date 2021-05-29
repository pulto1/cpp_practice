#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

namespace leo
{
	class string
	{
	public:
		string(const char* str = "")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

		string(const string& s)
		{
			_str = nullptr;
			string tmp = s._str;
			swap(_str, tmp._str);
		}

		string& operator=(const string& s)
		{
			if (s._str != _str)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

			~string()
		{
			delete[] _str;
			_str = nullptr;
		}

	private:
		char* _str;
	};
}

int main()
{
	leo::string s1 = "hello";
	leo::string s2 = "are";
	s2 = s1;
	return 0;
}