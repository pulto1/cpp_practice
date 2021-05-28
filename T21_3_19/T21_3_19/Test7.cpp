#define _CRT_SECURE_NO_WARNINGS

//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

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