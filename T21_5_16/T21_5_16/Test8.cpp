//给定一个二叉树，返回它的 后序 遍历。

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
            //保存左路结点
            while (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }

            //上面出来的结点，都是左节点被访问过的根结点。

            if (st.top()->right == prev || st.top()->right == nullptr)
            {
                v.push_back(st.top()->val);
                prev = st.top();
                st.pop();
            }

            //访问右
            else
            {
                cur = st.top()->right;
            }

        }

        return v;
    }

};