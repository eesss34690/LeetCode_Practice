class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<int, vector<pair<string,vector<int>>>> tot;
        map<int, vector<pair<string,vector<int>>>>::iterator iter;
        for (int i= 0; i< strs.size(); i++)
        {
            bool skip= 0;
            iter= tot.find(strs[i].length());
            vector<int> cnt(26, 0);
            for (int j= 0; j< strs[i].length(); j++)
            {
                cnt[strs[i][j]- 'a']++;
            }
            if (iter!= tot.end())
            {
                for (int j= 0; j< (iter->second).size()&& !skip; j++)
                {
                    if (cnt== (iter->second)[j].second)
                    {
                        for (int k= 0; k< ans.size()&& !skip; k++)
                        {
                            if (ans[k][0]== (iter->second)[j].first)
                            {
                                ans[k].push_back(strs[i]);
                                skip= 1;
                            }
                        }
                    }
                }
                if (!skip)
                {
                    vector<string> temp;
                    temp.push_back(strs[i]);
                    ans.push_back(temp);
                    (iter->second).push_back(pair<string, vector<int>>(strs[i], cnt));
                }               
            }
            else
            {
                vector<string> temp;
                temp.push_back(strs[i]);
                ans.push_back(temp);
                vector<pair<string, vector<int>>> temp_cnt;
                temp_cnt.push_back(pair<string, vector<int>>(strs[i], cnt));
                tot[strs[i].length()]= temp_cnt;
            }
        }
        return ans;
    }
};