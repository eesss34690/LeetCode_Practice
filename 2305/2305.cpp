class Solution {
public:
    int minmax(vector<int>& cookies, int idx, vector<int>& sum) {
        if (idx == cookies.size()) return *max_element(sum.begin(), sum.end());
        int ans = INT_MAX;
        for (int i = 0; i < sum.size(); i++)
        {
            sum[i] += cookies[idx];
            ans = min(ans, minmax(cookies, idx + 1, sum));
            sum[i] -= cookies[idx];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sum(k);
        return minmax(cookies, 0, sum);
    }
};
