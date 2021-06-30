#define _CRT_SECURE_NO_WARNINGS

//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0;
        int b = 0;
        for (auto e : nums)
        {
            a = (a ^ e) & ~b;
            b = (b ^ e) & ~a;
        }

        return a;
    }
};