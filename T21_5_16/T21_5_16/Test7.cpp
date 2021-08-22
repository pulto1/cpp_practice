//����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����
//
//�սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�

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