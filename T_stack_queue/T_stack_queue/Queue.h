#pragma once

#include <queue>

using namespace std;

namespace bit
{
    template<class T, class Con = deque<T>>
    class queue
    {
    public:
        void push(const T& x)
        {
            _c.push_back();
        }

        void pop()
        {
            _c.pop_front();
        }

        T& back()
        {
            _c.back();
        }

        const T& back()const
        {
            _c.back();
        }

        T& front()
        {
            _c.front();
        }

        const T& front()const
        {
            _c.front();
        }

        size_t size()const
        {
            _c.size();
        }

        bool empty()const
        {
            _c.empty();
        }
    private:
        Con _c;

    };
}
