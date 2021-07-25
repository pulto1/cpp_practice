//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳������4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С�
//��ע�⣺���������еĳ�������ȵģ�

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> st;

        int pushi = 0;
        int popi = 0;
        while (pushi != pushV.size())
        {
            st.push(pushV[pushi]);
            while (!st.empty() && popV[popi] == st.top())
            {
                popi++;
                st.pop();
            }
            pushi++;
        }

        if (popi == popV.size())
            return true;

        return false;
    }
};