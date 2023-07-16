class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skillmap;
        for (int i = 0; i < req_skills.size(); i++) skillmap[req_skills[i]] = i;
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << req_skills.size());
        dp[0] = {};
        int cur, comb;
        for (int i = 0; i < people.size(); i++)
        {
            cur = 0;
            for (auto &j : people[i]) cur |= 1 << skillmap[j];
            for (auto it = dp.begin(); it != dp.end(); it++)
            {
                comb = it->first | cur;
                if (dp.find(comb) == dp.end() || dp[comb].size() > 1 + dp[it->first].size())
                {
                    dp[comb] = it->second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << req_skills.size()) - 1];
    }
};
