class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length()) return ans;
        int cnt[26] = {0};
        int idx = 0, i = idx;
        for (; i < p.length(); i++)
        {
            cnt[s[i] - 'a']--;
            cnt[p[i] - 'a']++;
        }
        for (i = 0; i < 26 && cnt[i] == 0; i++);
        if (i == 26) ans.push_back(idx);
        while (idx < s.length() - p.length())
        {
            i = idx, idx++;
            cnt[s[i] - 'a']++;
            cnt[s[i + p.length()] - 'a']--;
            for (i = 0; i < 26 && cnt[i] == 0; i++);
            if (i == 26) ans.push_back(idx);
        }
        return ans;
    }
};
