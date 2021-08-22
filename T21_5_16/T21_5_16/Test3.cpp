//����һ�ö��������������ö���������ת����һ�������˫������

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Solution {
public:
    void _Convert(TreeNode* root, TreeNode*& prev)
    {
        if (root == nullptr)
            return;

        _Convert(root->left, prev);

        if (prev != nullptr)
            prev->right = root;
        root->left = prev;
        prev = root;

        _Convert(root->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;

        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);

        TreeNode* root = pRootOfTree;
        while (root->left != nullptr)
        {
            root = root->left;
        }

        return root;
    }
};