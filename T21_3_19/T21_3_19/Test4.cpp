#define _CRT_SECURE_NO_WARNINGS

//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
//
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
//
//����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���

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