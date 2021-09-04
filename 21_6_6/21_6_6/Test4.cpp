//给定两个数组，编写一个函数来计算它们的交集。
//
//说明：
//输出结果中的每个元素一定是唯一的。
//我们可以不考虑输出结果的顺序。

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