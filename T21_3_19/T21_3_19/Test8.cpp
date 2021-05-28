#define _CRT_SECURE_NO_WARNINGS

//给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
//
//如果剩余字符少于 k 个，则将剩余字符全部反转。
//如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

class Solution {
public:
    string reverseStr(string s, int k)
    {
        int i = 2 * k - 1;
        int end = i - k;
        int begin = end - k + 1;

        while (i < s.size())
        {
            while (begin < end)
            {
                swap(s[begin], s[end]);
                begin++;
                end--;
            }

            i += 2 * k;
            end = i - k;
            begin = end - k + 1;
        }

        if (end >= s.size())
        {
            end = s.size() - 1;
            while (begin < end)
            {
                swap(s[begin], s[end]);
                begin++;
                end--;
            }
        }

        else
        {
            while (begin < end)
            {
                swap(s[begin], s[end]);
                begin++;
                end--;
            }
        }

        return s;
    }
};