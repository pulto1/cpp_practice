//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������[1, 2, 3, 2, 2, 2, 5, 4, 2]����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
//����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ�ء�1 <= ���鳤�� <= 50000

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        vector<int> v1(50000, 0);
        for (auto e : numbers)
        {
            v1[e]++;
        }

        int val = 0;
        for (size_t i = 0; i < v1.size(); i++)
        {
            if (v1[i] > (numbers.size() / 2))
            {
                val = i;
                break;
            }

        }
        return val;
    }
};