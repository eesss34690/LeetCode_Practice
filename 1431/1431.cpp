class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), true);
        int gap = *max_element(candies.begin(), candies.end()) - extraCandies;
        for (int i = 0; i < candies.size(); i++) if (candies[i] < gap) ans[i] = false;
        return ans;
    }
};
