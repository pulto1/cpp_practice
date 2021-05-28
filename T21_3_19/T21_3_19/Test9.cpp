#define _CRT_SECURE_NO_WARNINGS

//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��

class Solution {
public:
    string reverseWords(string s)
    {
        size_t begin = 0;
        size_t end = s.find(' ', begin);
        while (end != string::npos)
        {
            size_t x1 = begin;
            size_t x2 = end - 1;
            while (x1 < x2)
            {
                swap(s[x1], s[x2]);
                x1++;
                x2--;
            }

            begin = end + 1;
            end = s.find(' ', begin);
        }

        end = s.size() - 1;
        while (begin < end)
        {
            swap(s[begin], s[end]);
            begin++;
            end--;
        }

        return s;
    }
};