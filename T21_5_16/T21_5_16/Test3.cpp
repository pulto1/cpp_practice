//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表

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