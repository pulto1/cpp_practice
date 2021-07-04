//����һ���������飬������������Ҳ�и�����
//�����е�һ������������������һ�������顣������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�Ϊ O(n).

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