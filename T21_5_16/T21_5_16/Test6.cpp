//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

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
    vector<vector<int>> levelOrder(TreeNode* root)
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

        return vv;
    }
};