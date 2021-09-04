//给定两个数组，编写一个函数来计算它们的交集。
//说明：
//输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
//我们可以不考虑输出结果的顺序。

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