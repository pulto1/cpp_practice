//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> count;
        for (auto i : nums)
        {
            count[i]++;
        }

        for (auto i : count)
        {
            if (i.second > 1)
                return true;
        }

        return false;
    }
};