#define _CRT_SECURE_NO_WARNINGS

//给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//
//进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        vector<int> v1;
        v1.resize(2, 0);

        int x = 0;
        for (auto e : nums)
        {
            x ^= e;
        }

        int pos = 0;
        for (int i = 0; i < 32; i++)
        {
            if (((x >> i) & 1) == 1)
            {
                pos = i;
                break;
            }
        }

        for (auto e : nums)
        {
            if (((e >> pos) & 1) == 1)
            {
                v1[0] ^= e;
            }

            else
            {
                v1[1] ^= e;
            }
        }

        return v1;
    }

};