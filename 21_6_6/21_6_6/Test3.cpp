//�����������飬��дһ���������������ǵĽ�����
//˵����
//��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ִ�������Сֵһ�¡�
//���ǿ��Բ�������������˳��

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> count1;
        for (auto i : nums1)
        {
            count1[i]++;
        }

        map<int, int> count2;
        for (auto i : nums2)
        {
            count2[i]++;
        }

        vector<int> v;
        for (auto i : count1)
        {
            if (count2[i.first] != 0)
            {
                int k = min(i.second, count2[i.first]);
                while (k--)
                {
                    v.push_back(i.first);
                }
            }
        }

        return v;
    }
};