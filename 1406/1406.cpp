class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> ans(stoneValue.size(), INT_MIN), cumulated(stoneValue.size());
        cumulated.back() = stoneValue.back();
        int i, j, temp;
        for (i = stoneValue.size() - 2; i >= 0 ; i--) cumulated[i] = cumulated[i + 1] + stoneValue[i];
        for (i = stoneValue.size() - 1; i >= 0 ; i--)
        {
            for (j = 3; j > 0; j--)
            {
                if (i + j >= stoneValue.size()) ans[i] = cumulated[i];
                else ans[i] = max(cumulated[i] - cumulated[i + j] - ans[i + j], ans[i]);
            }
        }
        if (ans[0] > 0) return "Alice";
        else if (ans[0] < 0) return "Bob";
        return "Tie";
    }
};
