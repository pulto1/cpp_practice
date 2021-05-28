#define _CRT_SECURE_NO_WARNINGS

//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

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