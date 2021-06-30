#define _CRT_SECURE_NO_WARNINGS

//����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;

        auto it = nums.begin();
        while (it != nums.end() - 1)
        {
            if (*it == *(it + 1))
            {
                nums.erase(it);
                it--;
            }
            it++;
        }

        return nums.size();
    }
};