#define _CRT_SECURE_NO_WARNINGS

//�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�

#include <iostream>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int arr[26] = { 0 };
        int flag = -1;
        for (auto ch : s)
        {
            arr[ch - 'a']++;
        }

        int i = 0;
        for (; i < s.size(); i++)
        {
            if (arr[s[i] - 'a'] == 1)
            {
                flag = 0;
                break;
            }
        }

        if (flag == -1)
        {
            cout << -1 << endl;
        }

        else
        {
            cout << s[i] << endl;
        }

    }

    return 0;
}