#define _CRT_SECURE_NO_WARNINGS

//����һ���������� nums ����ĳ��Ԫ�ؽ����� һ�� �⣬����ÿ��Ԫ�ض�ǡ���� ���� �������ҳ��������Ǹ�ֻ������һ�ε�Ԫ�ء�

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0;
        int b = 0;
        for (auto e : nums)
        {
            a = (a ^ e) & ~b;
            b = (b ^ e) & ~a;
        }

        return a;
    }
};