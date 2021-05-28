#define _CRT_SECURE_NO_WARNINGS

//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string sum;
        char next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            char x1 = 0;
            char x2 = 0;
            char ret = 0;

            if (end1 >= 0)
            {
                x1 = num1[end1] - '0';
                end1--;
            }

            if (end2 >= 0)
            {
                x2 = num2[end2] - '0';
                end2--;
            }

            ret = x1 + x2 + next;

            if (ret >= 10)
            {
                ret -= 10;
                next = 1;
            }

            else
            {
                next = 0;
            }

            sum += (ret + '0');
        }

        if (next == 1)
        {
            sum += '1';
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }
};