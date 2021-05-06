//#define _CRT_SECURE_NO_WARNINGS
//
////求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A ? B : C)
//
//class Solution;
//class Sum
//{
//    friend class Solution;
//public:
//    Sum()
//    {
//        _ret += _i;
//        _i++;
//    }
//
//    static int GetSum()
//    {
//        return _ret;
//    }
//
//private:
//    static int _i;
//    static int _ret;
//};
//
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution
//{
//public:
//    int Sum_Solution(int n)
//    {
//        Sum::_i = 1;
//        Sum::_ret = 0;
//        Sum arr[n];
//        return Sum::GetSum();
//    }
//};