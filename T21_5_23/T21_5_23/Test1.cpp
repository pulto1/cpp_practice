//输入一个英文句子，把句子中的单词(不区分大小写)按出现次数按从多到少把单词和次数在屏幕上输出来，
//次数一样的按照单词小写的字典序排序输出，要求能识别英文单词和句号。

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