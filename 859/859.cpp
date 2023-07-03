class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        int idx = -1, diff = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
            {
                if (diff > 0) return false;
                else if (idx == -1) idx = i;
                else if (s[i] == goal[idx] && s[idx] == goal[i]) diff++;
                else return false;
            }
        }
        if (diff > 0) return true;
        if (idx == -1)
        {
            int bit = 0;
            for (auto &i : s)
            {
                if (bit & (1 << (i - 'a'))) return true;
                else bit = bit | (1 << (i - 'a'));
            }
        }
        return false;
    }
};
