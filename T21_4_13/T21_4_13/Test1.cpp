//������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
//��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�

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