//�����������飬��дһ���������������ǵĽ�����
//
//˵����
//�������е�ÿ��Ԫ��һ����Ψһ�ġ�
//���ǿ��Բ�������������˳��

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s1;
        for (auto i : nums1)
        {
            s1.insert(i);
        }

        set<int> s2;
        for (auto i : nums2)
        {
            s2.insert(i);
        }

        vector<int> v;
        for (auto i : s1)
        {
            if (s2.find(i) != s2.end())
                v.push_back(i);
        }

        return v;
    }
};