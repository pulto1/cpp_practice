#define _CRT_SECURE_NO_WARNINGS

//����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� - 1��

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