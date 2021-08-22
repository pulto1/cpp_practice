//给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。

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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inbegin, int inend)
    {
        if (previ == preorder.size())
            return nullptr;

        //中序区间不存在
        if (inbegin > inend)
            return nullptr;

        //确定根在中序区间的位置，分割出左子树和右子树的中序
        int rooti = inbegin;
        while (rooti <= inend)
        {
            if (inorder[rooti] == preorder[previ])
                break;
            else
                rooti++;
        }

        //[inbegin, rooti - 1] rooti [rooti + 1, inend]
        TreeNode* root = new TreeNode(preorder[previ]);
        ++previ; //这个位置有些不好理解

        root->left = _buildTree(preorder, inorder, previ, inbegin, rooti - 1);
        root->right = _buildTree(preorder, inorder, previ, rooti + 1, inend);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int previ = 0;
        return _buildTree(preorder, inorder, previ, 0, inorder.size() - 1);
    }

};