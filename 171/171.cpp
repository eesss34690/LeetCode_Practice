class Solution {
public:
    int titleToNumber(string s) {
        int ans= 0;
        long int cnt= 1;
        reverse(begin(s), end(s));
        for (auto &i: s)
        {
            ans+= cnt* (i- 'A'+ 1);
            cnt*= 26;
        }
        return ans;
    }
};