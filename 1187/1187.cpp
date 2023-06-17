class Solution {
public:
    int dp[2001][2001];
    int solve (vector<int>& arr1, vector<int>& arr2, int i, int j, int prev) {
        if (i == arr1.size()) return 0;
        j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
        if (dp[i][j] != -1) return dp[i][j];
        if (arr1[i] <= prev && j == arr2.size()) return 2001;
        int take = (j == arr2.size()) ? 2001 : 1 + solve(arr1, arr2, i + 1, j + 1, arr2[j]);
        int notake = (arr1[i] > prev) ? solve(arr1, arr2, i + 1, j, arr1[i]) : 2001;
        return dp[i][j] = min(take, notake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp, -1, sizeof(dp));
        sort(arr2.begin(), arr2.end());
        int ans = solve(arr1, arr2, 0, 0, -1);
        return (ans > arr1.size()) ? -1 : ans;
    }
};