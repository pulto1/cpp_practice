#define _CRT_SECURE_NO_WARNINGS

//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0

class Solution {
public:
    int StrToInt(string str)
    {
        int flag = 1;
        int i = 0;
        if (str[0] == '+')
        {
            i++;
        }

        else if (str[0] == '-')
        {
            flag = -1;
            i++;
        }

        else if (isdigit(str[0]))
        {
            ;
        }

        else
        {
            return 0;
        }

        int num = 0;
        while (i < str.size())
        {
            if (isdigit(str[i]))
            {
                num = (num * 10) + (str[i] - '0');
                i++;
            }

            else
            {
                return 0;
            }
        }

        num *= flag;
        return num;
    }
};