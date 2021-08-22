//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//
//空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

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
    void _tree2str(TreeNode* root, string& s)
    {
        if (root == nullptr)
            return;

        s += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr)
            return;

        s += '(';
        _tree2str(root->left, s);
        s += ')';

        if (root->right != nullptr)
        {
            s += '(';
            _tree2str(root->right, s);
            s += ')';
        }
    }

    string tree2str(TreeNode* root)
    {
        string s;
        _tree2str(root, s);

        return s;
    }
};