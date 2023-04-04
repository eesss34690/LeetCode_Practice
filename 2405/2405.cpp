class Solution {
public:
    int partitionString(string s) {
        vector<bool> vec(26, false);
        vector<bool> temp(26, false);
        int idx = s.length() - 1, ans = 1;
        while (idx >= 0)
        {
            if (vec[s[idx] - 'a'])
            {
                vec = temp;
                ans++;
            }
            vec[s[idx] - 'a'] = true;
            idx--;
        }
        return ans;
    }
};