//����һ��������������������������������
//
//ע�� :
//����Լ�������û���ظ���Ԫ�ء�

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