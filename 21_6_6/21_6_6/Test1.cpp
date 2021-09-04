//给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
//如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
//返回所有不常用单词的列表。
//您可以按任何顺序返回列表。

class Solution {
public:
    void SaveWords(vector<string>& v, string str)
    {
        int i = 0;
        while (i < str.size())
        {
            string s;
            while (!isspace(str[i]) && str[i])
            {
                s.push_back(str[i]);
                i++;
            }
            v.push_back(s);
            i++;
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> v1;
        SaveWords(v1, s1);
        vector<string> v2;
        SaveWords(v2, s2);

        map<string, int> CountWords;
        for (auto str : v1)
        {
            CountWords[str]++;
        }

        for (auto str : v2)
        {
            CountWords[str]++;
        }

        vector<string> UnWords;
        for (auto m : CountWords)
        {
            if (m.second == 1)
                UnWords.push_back(m.first);
        }

        return UnWords;
    }
};