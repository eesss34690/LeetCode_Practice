class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len = mat.size() / 2, ans = (mat.size() % 2 == 1) ? mat[len][len] : 0, whole = mat.size() - 1;
        for (int i = 0; i < len; i++)
            ans += mat[i][i] + mat[whole - i][i] + mat[i][whole - i] + mat[whole - i][whole - i];
        return ans;
    }
};
