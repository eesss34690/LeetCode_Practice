class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans[questions.size() + 1];
        ans[questions.size()] = 0;
        for (int i = questions.size() - 1; i >= 0; i--)
        {
            ans[i] = (i + questions[i][1] + 1 >= questions.size()) ? questions[i][0] : questions[i][0] + ans[i + questions[i][1] + 1];
            ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans[0];
    }
};
