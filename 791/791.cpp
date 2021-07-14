class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> text(26, 0);
        string ans;
        for (auto &i: str)
        {
            text[i- 'a']++;
        }
        for (auto &i: order)
        {
            for (int j= 0; j< text[i- 'a']; j++)
            {
                ans+= i;
            }
            text[i- 'a']= 0;
        }
        for (int i= 0; i< 26; i++)
        {
            for (int j= 0; j< text[i]; j++)
                ans+= (i+ 'a');
        }
        return ans;
    }
};
