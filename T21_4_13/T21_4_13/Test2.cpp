//根据 逆波兰表示法，求表达式的值。
//有效的算符包括  + 、 - 、 * 、 / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//
//说明：
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;

        for (auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                switch (str[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                default:
                    break;
                }
            }

            else
            {
                st.push(stoi(str));
            }
        }

        return st.top();
    }
};