#define _CRT_SECURE_NO_WARNINGS

//�����ַ������һ�����ʵĳ��ȣ������Կո�������ַ�������С��5000��

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    if (s.size() == 0)
        cout << 0 << endl;

    else
    {
        size_t pos = s.rfind(' ');
        if (pos != string::npos)
        {
            cout << s.size() - pos - 1 << endl;
        }

        else
        {
            cout << s.size() << endl;
        }
    }

    return 0;
}