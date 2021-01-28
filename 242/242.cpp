class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!= t.size())
            return false;
        vector<int> cnt_s(26, 0);
        vector<int> cnt_t(26, 0);
        for (int i= 0; i< s.size(); i++)
        {
            cnt_s[s[i]- 'a']++;
            cnt_t[t[i]- 'a']++;
        }
        if (cnt_s== cnt_t)
            return true;
        return false;
    }
};