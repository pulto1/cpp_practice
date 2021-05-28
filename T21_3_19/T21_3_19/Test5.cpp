#define _CRT_SECURE_NO_WARNINGS

//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 - 1。

class Solution {
public:
    int firstUniqChar(string s)
    {
        int chArr[26] = { 0 };

        for (auto ch : s)
        {
            chArr[ch - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (chArr[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};