//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
//
//�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T �������ڵ� p��q������������ȱ�ʾΪһ���ڵ� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

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