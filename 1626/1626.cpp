class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ages_rank(ages.size());
        for (int i = 0; i < ages.size(); i++)
            ages_rank[i] = make_pair(ages[i], scores[i]);
        sort(ages_rank.begin(), ages_rank.end());
        int ans, dp[ages.size()];
        for (int i = 0; i < ages_rank.size(); i++)
        {
            dp[i] = ages_rank[i].second;
            for(int j = 0; j < i; j++) {
                if(ages_rank[j].second <= ages_rank[i].second)
                    dp[i] = max(dp[i], dp[j] + ages_rank[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
