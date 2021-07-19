#pragma once

#include <iostream>

using namespace std;

namespace bit
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_val(val)
            ,_pNext(nullptr)
            ,_pPre(nullptr)
        {}

        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };

    //List的迭代器类
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}

        T& operator*()
        {
            return _pNode->_val;
        }

        T* operator->()
        {
            return &(_pNode->_val);
        }

        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }

        Self operator++(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pNext;

            return tmp;
        }

        Self& operator--()
        {
            _pNode = _pNode->_pPre;

            return *this;
        }

        Self& operator--(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pPre;

            return tmp;
        }

        bool operator!=(const Self& l)
        {
            return !(_pNode->_val == l._pNode->_val);
        }

        bool operator==(const Self& l)
        {
            return (_pNode->_val == l._pNode->_val);
        }

        PNode _pNode;
    };

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:
        // List的构造
        list()
        {
            CreateHead();
        }

        list(int n, const T& value = T())
        {
            CreateHead();
            while (n--)
            {
                push_back(value);
            }
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        list(const list<T>& l)
        {
            CreateHead();
            list<T> tmp(l.begin(), l.end());
            std::swap(tmp._pHead, _pHead);
        }

        list<T>& operator=(const list<T> l)
        {
            std::swap(_pHead, l._pHead);

            return *this;
        }

        ~list()
        {
            clear();

            delete _pHead;
            _pHead = nullptr;
        }

        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
        }
        iterator end()
        {
            return _pHead;
        }

        const_iterator begin() const
        {
            return _pHead->_pNext;
        }

        const_iterator end() const
        {
            return _pHead;
        }

        // List Capacity
        size_t size()const
        {
            size_t count = 0;
            const_iterator it = begin();
            while (it != end())
            {
                count++;
                it++;
            }

            return count;
        }

        bool empty()const
        {
            return _pHead == _pHead->_pNext;
        }

        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }

        const T& front()const
        {
            return _pHead->_pNext->_val;
        }

        T& back()
        {
            return _pHead->_pPre->_val;
        }
        const T& back()const
        {
            return _pHead->_pPre->_val;
        }

        // List Modify
        void push_back(const T& val)
        { 
            insert(begin(), val);
        }

        void pop_back()
        { 
            erase(--end());
        }

        void push_front(const T& val)
        { 
            insert(begin(), val);
        }

        void pop_front()
        { 
            erase(begin());
        }

        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* node = new Node(val);
            Node* cur = pos._pNode;
            Node* prev = cur->_pPre;

            node->_pNext = cur;
            cur->_pPre = node;

            node->_pPre = prev;
            prev->_pNext = node;

            return iterator(node);
        }

        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            Node* prev = pos._pNode->_pPre;
            Node* next = pos._pNode->_pNext;

            delete pos._pNode;

            prev->_pNext = next;
            next->_pPre = prev;

            return iterator(next);
        }

        void clear()
        {
            Node* cur = _pHead->_pNext;
            while (cur != _pHead)
            {
                cur = cur->_pNext;
                delete cur->_pPre;
            }
        }

        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
        }

    private:
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
        }
        PNode _pHead;
    };
};