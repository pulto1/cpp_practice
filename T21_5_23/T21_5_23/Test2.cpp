//给一非空的单词列表，返回前 k 个出现次数最多的单词。
//
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> countMap;
        for (auto str : words)
        {
            countMap[str]++;
        }

        multimap<int, string, greater<int>> sortMap;
        for (auto k : countMap)
        {
            sortMap.insert(make_pair(k.second, k.first));
        }

        vector<string> sortString;

        for (auto v : sortMap)
        {
            sortString.push_back(v.second);
            k--;
            if (k == 0)
            {
                break;
            }
        }

        return sortString;
    }
};