class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        int s1Cnt[26] = {0};
        int i, j;
        for (i = 0; i < s1.length(); i++)
        {
            s1Cnt[s1[i] - 'a']++;
            s1Cnt[s2[i] - 'a']--;
        }
        for (i = 0; i < 26; i++)
            if (s1Cnt[i] != 0) break;
        if (i == 26) return true;
        for (i = 0; i < s2.length() - s1.length(); i++)
        {
            s1Cnt[s2[i] - 'a']++;
            s1Cnt[s2[i + s1.length()] - 'a']--;
            for (j = 0; j < 26; j++)
                if (s1Cnt[j] != 0) break;
            if (j == 26) return true;
        }
        return false;
    }
};
