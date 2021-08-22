//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Find(TreeNode* root, TreeNode* x, stack<TreeNode*>& st)
    {
        if (root == nullptr)
            return false;

        st.push(root);
        if (root == x)
            return true;

        bool flag1 = Find(root->left, x, st);
        bool flag2 = Find(root->right, x, st);

        if (flag1 == false && flag2 == false)
        {
            st.pop();
            return false;
        }

        return true;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> qSt;
        stack<TreeNode*> pSt;
        Find(root, q, qSt);
        Find(root, p, pSt);

        while (qSt.size() < pSt.size())
        {
            pSt.pop();
        }

        while (qSt.size() > pSt.size())
        {
            qSt.pop();
        }

        while (pSt.top() != qSt.top())
        {
            pSt.pop();
            qSt.pop();
        }

        return qSt.top();
    }
};