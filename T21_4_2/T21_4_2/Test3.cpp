//输入一个整型数组，数组里有正数也有负数。
//数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int gap = 0;
        int max = array[0];
        while (gap < array.size())
        {
            for (size_t i = 0; i + gap < array.size(); i++)
            {
                int sum = 0;
                int j = 0;
                while (j <= gap)
                {
                    sum += array[i + j];
                    j++;
                }
                if (sum > max)
                    max = sum;
            }
            gap++;
        }

        return max;
    }
};