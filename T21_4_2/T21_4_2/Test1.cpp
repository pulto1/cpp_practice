//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组[1, 2, 3, 2, 2, 2, 5, 4, 2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。1 <= 数组长度 <= 50000

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        vector<int> v1(50000, 0);
        for (auto e : numbers)
        {
            v1[e]++;
        }

        int val = 0;
        for (size_t i = 0; i < v1.size(); i++)
        {
            if (v1[i] > (numbers.size() / 2))
            {
                val = i;
                break;
            }

        }
        return val;
    }
};