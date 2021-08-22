//����һ������ǰ����� preorder ���������  inorder���빹�����������������ڵ㡣

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

        //�������䲻����
        if (inbegin > inend)
            return nullptr;

        //ȷ���������������λ�ã��ָ����������������������
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
        ++previ; //���λ����Щ�������

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