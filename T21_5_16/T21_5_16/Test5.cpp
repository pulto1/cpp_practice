//给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> vv;
        if (root == nullptr)
            return vv;


        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty())
        {
            int count = q.size();

            vector<int> v;

            while (count--)
            {
                if (q.front()->left)
                    q.push(q.front()->left);

                if (q.front()->right)
                    q.push(q.front()->right);

                v.push_back(q.front()->val);
                q.pop();
            }

            vv.push_back(v);

        }

        reverse(vv.begin(), vv.end());
        return vv;
    }
};