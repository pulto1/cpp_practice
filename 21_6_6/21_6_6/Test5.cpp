//�ڴ�СΪ 2N ������ A ���� N + 1 ����ͬ��Ԫ�أ�������һ��Ԫ���ظ��� N �Ρ�
//�����ظ��� N �ε��Ǹ�Ԫ�ء�

class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        map<int, int> count;
        for (auto i : nums)
        {
            count[i]++;
        }

        for (auto i : count)
        {
            if (i.second == nums.size() / 2)
                return i.first;
        }

        return -1;
    }
};