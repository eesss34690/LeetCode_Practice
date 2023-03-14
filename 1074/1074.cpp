class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() + 1, col = matrix[0].size() + 1;
        vector<vector<int>> summation(row, vector<int>(col));
        for (int i = 0; i < row; i++)
            summation[i][0] = 0;
        for (int i = 1; i < col; i++)
            summation[0][i] = 0;
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
                summation[i][j] = summation[i][j - 1] + matrix[i - 1][j - 1] + summation[i - 1][j] - summation[i - 1][j - 1];
        }
        int ans = 0;
        for (int lx = 1; lx < row; lx++)
        {
            for (int rx = lx; rx < row; rx++)
            {
                for (int ly = 1; ly < col; ly++)
                {
                    for (int ry = ly; ry < col; ry++)
                    {
                        if (summation[rx][ry] + summation[lx - 1][ly - 1] - summation[rx][ly - 1] - summation[lx - 1][ry] == target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
