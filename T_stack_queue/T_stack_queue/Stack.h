#pragma once

#include<iostream>
#include <queue>

using namespace std;

namespace bit
{
    template<class T, class Con = deque<T>>
    class stack
    {
    public:
        void push(const T& x)
        {
            _c.push_back();
        }

        void pop()
        {
            _c.pop_back();
        }

        T& top()
        {
            return _c.back();
        }

        const T& top()const
        {
            return _c.back();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }
    
    private:
        Con _c;
    };
}