//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//
//注意：
//你只能使用队列的基本操作 —— 也就是 push to back、peek / pop from front、size 和 is empty 这些操作。
//你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x)
    {
        if (Q1.empty() && Q2.empty())
        {
            Q1.push(x);
        }

        else
        {
            !Q1.empty() ? Q1.push(x) : Q2.push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int top = 0;
        if (Q1.empty())
        {
            while (Q2.size() > 1)
            {
                int tmp = Q2.front();
                Q2.pop();
                Q1.push(tmp);
            }

            top = Q2.back();
            Q2.pop();
        }

        else
        {
            while (Q1.size() > 1)
            {
                int tmp = Q1.front();
                Q1.pop();
                Q2.push(tmp);
            }

            top = Q1.back();
            Q1.pop();
        }

        return top;
    }

    /** Get the top element. */
    int top()
    {
        return Q1.empty() ? Q2.back() : Q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return Q1.empty() && Q2.empty();
    }

private:
    queue<int> Q1;
    queue<int> Q2;
};