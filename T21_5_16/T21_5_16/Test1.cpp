//根据一棵树的中序遍历与后序遍历构造二叉树。
//
//注意 :
//你可以假设树中没有重复的元素。

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
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& preorder, int& previ, int inbegin, int inend)
    {
        if (previ < 0)
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

        --previ;
        root->right = _buildTree(inorder, preorder, previ, rooti + 1, inend);
        root->left = _buildTree(inorder, preorder, previ, inbegin, rooti - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int previ = inorder.size() - 1;
        return _buildTree(inorder, postorder, previ, 0, inorder.size() - 1);
    }
};