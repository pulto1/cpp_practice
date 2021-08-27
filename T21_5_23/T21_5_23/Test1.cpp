//����һ��Ӣ�ľ��ӣ��Ѿ����еĵ���(�����ִ�Сд)�����ִ������Ӷൽ�ٰѵ��ʺʹ�������Ļ���������
//����һ���İ��յ���Сд���ֵ������������Ҫ����ʶ��Ӣ�ĵ��ʺ;�š�

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

void ToLower(string& str)
{
    for (auto& s : str)
    {
        if (isupper(s))
        {
            s = tolower(s);
        }
    }
}

int main()
{
    string sentence;
    getline(cin, sentence);
    ToLower(sentence);

    vector<string> sentenceArr;
    int i = 0;
    while (sentence[i] != '.' && sentence[i] != '\0')
    {
        string s;
        while (sentence[i] != '.' && sentence[i] != ' ' && sentence[i] != '\0')
        {
            s.push_back(sentence[i]);
            i++;
        }
        sentenceArr.push_back(s);
        i++;
    }

    map<string, int> countMap;
    for (auto& str : sentenceArr)
    {
        countMap[str]++;
    }

    multimap<int, string, greater<int>> sortMap;
    for (auto& i : countMap)
    {
        sortMap.insert(make_pair(i.second, i.first));
    }

    for (auto& str : sortMap)
    {
        cout << str.second << ":" << str.first << endl;
    }

    return 0;
}