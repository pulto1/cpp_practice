//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, greater<int> > kMinHeap(nums.begin(), nums.begin() + k);

        for (size_t i = k; i < nums.size(); i++)
        {
            if (nums[i] > kMinHeap.top())
            {
                kMinHeap.pop();
                kMinHeap.push(nums[i]);
            }
        }

        return kMinHeap.top();
    }
};