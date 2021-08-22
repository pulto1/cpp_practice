//����һ������������������ ���� ������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> v;

        if (root == nullptr)
            return v;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur != nullptr || !st.empty())
        {
            //������·���
            while (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }

            //��������Ľ�㣬������ڵ㱻���ʹ��ĸ���㡣

            if (st.top()->right == prev || st.top()->right == nullptr)
            {
                v.push_back(st.top()->val);
                prev = st.top();
                st.pop();
            }

            //������
            else
            {
                cur = st.top()->right;
            }

        }

        return v;
    }

};