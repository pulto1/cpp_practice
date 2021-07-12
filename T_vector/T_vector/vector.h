#pragma once

#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

namespace bit
{
    template<class T>
    class vector
    {
    public:        
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;
            
        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

        // construct and destroy
        vector()
            : _start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {}

        vector(int n, const T& value = T())
        {
            _start = new T[n];
            for (int i = 0; i < n; i++)
            {
                _start[i] = value;
            }

            _finish = _endOfStorage = _start + n;
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            int sz = last - first;
            _start = new T[sz];
            InputIterator it = first;
            
            for (int i = 0; i < sz; i++)
            {
                _start[i] = *it;
                it++;
            }

            _finish = _endOfStorage = _start + sz;
        }

        vector(const vector<T>& v)
            : _start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr)
        {
            vector<T> tmp(v.begin(), v.end());
            std::swap(_start, tmp._start);
            std::swap(_finish, tmp._finish);
            std::swap(_endOfStorage, tmp._endOfStorage);
        }

        vector<T>& operator= (vector<T> v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);

            return *this;
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }

        // capacity
        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _endOfStorage - _start;
        }

        void reserve(size_t n)
        { 
            size_t sz = size();
            if (capacity() < n)
            {
                iterator tmp = new T[n];
                for (size_t i = 0; i < sz; i++)
                {
                    tmp[i] = _start[i];
                }

                std::swap(_start, tmp);
                _finish = _start + sz;
                _endOfStorage = _start + n;
                delete[] tmp;
            }
        }

        void resize(size_t n, const T& value = T())
        {
            if (n <= size())
            {
                _finish = _start + n;
            }

            else
            {
                if (n > capacity())
                    reserve(n);

                while (_finish != _start + n)
                {
                    *_finish = value;
                    _finish++;
                }
            }
        }

        ///////////////access///////////////////////////////
        T& operator[](size_t pos)
        {
            return _start[pos];
        }
        const T& operator[](size_t pos)const
        {
            return _start[pos];
        }

        ///////////////modify/////////////////////////////
        void push_back(const T& x)
        {
            if (_finish == _endOfStorage)
            {
                capacity() == 0 ? reserve(4) : reserve(capacity() * 4);
            }

            *_finish = x;
            _finish++;
        }

        void pop_back()
        {
            assert(size() > 0);
            _finish--;
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);
        }

        iterator insert(iterator pos, const T& x)
        {
            int len = pos - _start;
            if (_finish == _endOfStorage)
            {
                capacity == 0 ? reserve(4) : reserve(capacity() * 4);
            }

            pos = _start + pos;

            iterator end = _finish;
            while (end > pos )
            {
                *end = *(end - 1);
                end--;
            }

            *pos = x;

            return pos;
        }

        iterator erase(iterator pos)
        {
            assert(size() > 0);

            while (pos < _finish - 1)
            {
                *pos = *(pos + 1);
                pos++;
            }

            _finish--;

            return pos;
        }

    private:
        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _endOfStorage; // 指向存储容量的尾
    };
}