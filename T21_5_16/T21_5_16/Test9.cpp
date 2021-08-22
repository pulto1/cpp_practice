//����һ���������ĸ��ڵ� root ���������� ���� ������

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        //cur��Ϊ�ա���ʾ������û�п�ʼ����
        //st��Ϊ�գ���ʾ���н���������û�з���
        while (cur || !st.empty())
        {
            //1.���ʲ�������·����ջ
            while (cur)
            {

                st.push(cur);
                cur = cur->left;
            }

            //2.����root�������ʣ�µ�����·����������û�з���
            //���δ�ջ�����ó�������
            TreeNode* top = st.top();
            v.push_back(top->val);
            st.pop();

            //�����⣬������
            cur = top->right;
        }

        return v;
    }
};