//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {

        vector<string> v1(10, string());
        v1[2] = "abc";
        v1[3] = "def";
        v1[4] = "ghi";
        v1[5] = "jkl";
        v1[6] = "mno";
        v1[7] = "pqrs";
        v1[8] = "tuv";
        v1[9] = "wxyz";

        vector<string> v2;
        if (digits == "")
            return v2;

        size_t sz = digits.size();
        for (size_t i = 0; i < v1[digits[0] - '0'].size(); i++)
        {
            if (sz == 1)
            {
                string tmp;
                tmp.push_back(v1[digits[0] - '0'][i]);
                v2.push_back(tmp);
            }

            else
            {
                for (size_t j = 0; j < v1[digits[1] - '0'].size(); j++)
                {
                    if (sz == 2)
                    {
                        string tmp;
                        tmp.push_back(v1[digits[0] - '0'][i]);
                        tmp.push_back(v1[digits[1] - '0'][j]);
                        v2.push_back(tmp);
                    }

                    else
                    {
                        for (size_t k = 0; k < v1[digits[2] - '0'].size(); k++)
                        {
                            if (sz == 3)
                            {
                                string tmp;
                                tmp.push_back(v1[digits[0] - '0'][i]);
                                tmp.push_back(v1[digits[1] - '0'][j]);
                                tmp.push_back(v1[digits[2] - '0'][k]);
                                v2.push_back(tmp);
                            }

                            else
                            {
                                for (size_t l = 0; l < v1[digits[3] - '0'].size(); l++)
                                {
                                    string tmp;
                                    tmp.push_back(v1[digits[0] - '0'][i]);
                                    tmp.push_back(v1[digits[1] - '0'][j]);
                                    tmp.push_back(v1[digits[2] - '0'][k]);
                                    tmp.push_back(v1[digits[3] - '0'][l]);
                                    v2.push_back(tmp);
                                }
                            }
                        }
                    }
                }
            }
        }

        return v2;
    }
};