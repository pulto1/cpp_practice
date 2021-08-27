//��һ�ǿյĵ����б�����ǰ k �����ִ������ĵ��ʡ�
//
//���صĴ�Ӧ�ð����ʳ���Ƶ���ɸߵ������������ͬ�ĵ�������ͬ����Ƶ�ʣ�����ĸ˳������

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