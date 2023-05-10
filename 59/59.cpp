class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, buttom = n - 1, left = 0, right = n - 1, cnt = 1, i;
        while (top <= buttom)
        {
            for (i = left; i <= right; i++) ans[top][i] = cnt++;
            top++;
            if (top <= buttom)
            {
                for (i = top; i <= buttom; i++) ans[i][right] = cnt++;
                right--;
                for (i = right; i >= left; i--) ans[buttom][i] = cnt++;
                buttom--;
                for (i = buttom; i >= top; i--) ans[i][left] = cnt++;
                left++;
            }
        }
        return ans;
    }
};
