//给定一个二叉树的根节点 root ，返回它的 中序 遍历。

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

        //cur不为空。表示还有树没有开始访问
        //st不为空，表示还有结点的右子树没有访问
        while (cur || !st.empty())
        {
            //1.访问并保存左路结点进栈
            while (cur)
            {

                st.push(cur);
                cur = cur->left;
            }

            //2.对于root这颗数，剩下的是左路结点的右子树没有访问
            //依次从栈里面拿出来访问
            TreeNode* top = st.top();
            v.push_back(top->val);
            st.pop();

            //子问题，走右树
            cur = top->right;
        }

        return v;
    }
};