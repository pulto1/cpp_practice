#pragma once

#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

namespace leo
{
    class string
    {
    public:
        typedef char* iterator;
        const static size_t npos;
    public:
        string(const char* str = "")
        {
            int len = strlen(str);
            _str = new char[len + 1];
            strcpy(_str, str);
            _size = _capacity = len;
        }
            string(const string& s)
        {
            _str = nullptr;
            _size = _capacity = 0;
            string tmp = s._str;
            std::swap(_size, tmp._size);
            std::swap(_str, tmp._str);
            std::swap(_capacity, tmp._capacity);
        }

        string& operator=(string s)
        {
                std::swap(_size, s._size);
                std::swap(_str, s._str);
                std::swap(_capacity, s._capacity);

                return *this;
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        /////////////////////////////////////////////////////////////
        // iterator
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }

        /////////////////////////////////////////////////////////////
        // modify
        void push_back(char c)
        {
            if (_size == _capacity)
            {
                _capacity *= 2;
                char* tmp = new char[_capacity + 1];
                strcpy(tmp, _str);
                std::swap(_str, tmp);
                delete[] tmp;
            }

            _str[_size] = c;
            _str[++_size] = '\0';
        }

        string& operator+=(char c)
        {
            push_back(c);
            return *this;
        }

        void append(const char* str)
        {
            int len = strlen(str);
            if (_size + len > _capacity)
            {
                _capacity = _size + len;
                char* tmp = new char[_capacity + 1];
                strcpy(tmp, _str);
                std::swap(_str, tmp);
                delete[] tmp;
            }

            strcpy(_str + _size, str);
            _size += len;
        }

        string& operator+=(const char* str)
        {
            append(str);

            return *this;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        void swap(string& s)
        {
            std::swap(_size, s._size);
            std::swap(_str, s._str);
            std::swap(_capacity, s._capacity);
        }

        const char* c_str()const
        {
            return _str;
        }

        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const
        {
            return _size;
        }

        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            if (_size == 0)
            {
                return true;
            }

            return false;
        }
        void resize(size_t n, char c = '\0')
        {
            if (n < _size)
            {
                _size = n;
                _str[_size] = '\0';
            }

            else
            {
                if (n > _capacity)
                {
                    reserve(n);
                }

                for (size_t i = _size; i < n; i++)
                {
                    _str[i] = c;
                }

                _size = n;
                _str[_size] = '\0';
            }
        }

        void reserve(size_t n)
        {
            _capacity = n;
            char* tmp = new char[_capacity + 1];
            strcpy(tmp, _str);
            std::swap(_str, tmp);
            delete[] tmp;
        }

        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index)
        {
            return _str[index];
        }

        const char& operator[](size_t index)const
        {
            return _str[index];
        }

        /////////////////////////////////////////////////////////////
        //relational operators
        bool operator<(const string& s)
        {
            return !(*this >= s);
        }
        bool operator<=(const string& s)
        {
            return !(*this > s);
        }

        bool operator>(const string& s)
        {
            size_t i = 0;
            while (i < _size && i < s._size)
            {
                if (_str[i] < s._str[i])
                {
                    return false;
                }

                if (_str[i] > s._str[i])
                {
                    return true;
                }

                i++;
            }

            if (i < _size)
            {
                return true;
            }

            return false;
        }
        bool operator>=(const string& s)
        {
            return (*this > s && *this == s);
        }

        bool operator==(const string& s)
        {
            size_t i = 0;
            while (i < _size && i < s._size)
            {
                if (_str[i] < s._str[i])
                {
                    return false;
                }

                if (_str[i] > s._str[i])
                {
                    return false;
                }

                i++;
            }

            if (_size && s._size)
            {
                return true;
            }

            return false;
        }
        bool operator!=(const string& s)
        {
            return !(*this == s);
        }

        /////////////////////////////////////////////////////////////
        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const
        {
            assert(pos < _size);

            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == c)
                {
                    return i;
                }
            }

            return npos;
        }

        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const
        {
            assert(pos < _size);

            char* tmp = strstr(_str, s);
            if (tmp == nullptr)
            {
                return npos;
            }

            return tmp - _str;
        }

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {
            assert(pos < _size);

            if (_size == _capacity)
            {
                _capacity == 0 ? _capacity = 4 : _capacity *= 2;
                reserve(_capacity);
            }

            size_t end = _size + 1;
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                end--;
            }

            _str[pos] = c;
            _size++;
            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos < _size);

            size_t len = strlen(str);
            if (len == 0)
                return *this;

            if (_size + len > _capacity)
            {
                _capacity = _size + len;
                reserve(_capacity);
            }

            size_t end = _size + len + 1;
            while (end >= pos + len)
            {
                _str[end] = _str[end - len];
                end--;
            }

            strncpy(_str + pos, str, len);
            _size += len;
            return *this;
        }

        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len)
        {
            assert(pos < _size);

            size_t i = pos;
            _size -= len;
            while (i <= _size)
            {
                _str[i] = _str[i + len];
                i++;
            }

            return *this;
        }

    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };

    const size_t string::npos = -1;

    ostream& operator<<(ostream& _cout, const leo::string& s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            _cout << s[i];
        }

        return _cout;
    }

    istream& operator>>(istream& _cin, leo::string& s)
    {
        s.clear();
        char ch;
        while (1)
        {
            ch = getchar();
            if (ch == ' ' || ch == '\n')
            {
                break;
            }

            s += ch;
        }

        return _cin;
    }
}