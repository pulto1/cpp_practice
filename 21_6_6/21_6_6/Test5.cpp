//在大小为 2N 的数组 A 中有 N + 1 个不同的元素，其中有一个元素重复了 N 次。
//返回重复了 N 次的那个元素。

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