#define _CRT_SECURE_NO_WARNINGS

//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˵����
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int x = 0;
        for (auto e : nums)
        {
            x ^= e;
        }

        return x;
    }
};