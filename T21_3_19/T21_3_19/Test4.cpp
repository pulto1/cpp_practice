#define _CRT_SECURE_NO_WARNINGS

//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

void swap(char* s1, char* s2)
{
    char tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
void reverseString(char* s, int sSize)
{
    int begin = 0;
    int end = sSize - 1;
    while (begin < end)
    {
        swap(&s[begin], &s[end]);
        end--;
        begin++;
    }

    return s;
}