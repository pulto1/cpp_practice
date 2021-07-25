//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) —— 将元素 x 推入栈中。
//pop() —— 删除栈顶的元素。
//top() —— 获取栈顶元素。
//getMin() —— 检索栈中的最小元素。

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val)
    {
        st.push(val);
        if (minST.empty() || minST.top() >= val)
            minST.push(val);
    }

    void pop()
    {
        if (st.top() == minST.top())
        {
            minST.pop();
        }
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minST.top();
    }

private:
    stack<int> st;
    stack<int> minST;
};