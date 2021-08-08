class Solution {
    //EDEEDBABCD
public:
    int minCut(string s) {
        int si= s.length(), option1, option2;
        vector<int> dp(si, -1);
        dp[0]= 0;
        for (int i= 1; i< si; i++)
        {
            dp[i]= dp[i- 1]+ 1;
            int j= 0;
            for (; j< i; j++)
            {
                if (s[j]!= s[i])
                    continue;
                int r= i- 1, l= j+ 1;
                while (l< r)
                {
                    if (s[r]!= s[l])
                        break;
                    l++, r--;
                }
                if (l>= r)
                {
                    dp[i]= (j> 0)? ((dp[i]> dp[j- 1]+ 1)? dp[j- 1]+ 1: dp[i]): 0;
                }
            }
        }
        return dp[si- 1];
    }
};
