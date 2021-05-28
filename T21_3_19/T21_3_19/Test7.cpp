#define _CRT_SECURE_NO_WARNINGS

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。

class Solution {
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (!(isdigit(s[i]) || isalpha(s[i])))
            {
                s.erase(i, 1);
                i--;
            }
        }

        if (s.size() == 0)
            return true;

        int begin = 0;
        int end = s.size() - 1;

        while (begin < end)
        {
            if ((begin < end) && (toupper(s[begin]) == toupper(s[end])))
            {
                end--;
                begin++;
            }

            else
            {
                return false;
            }
        }

        return true;
    }
};