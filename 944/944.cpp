class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int i = 1; i < strs.size(); i++)
        {
            for (int j = 0; j < strs[0].length(); j++)
            {
                if (strs[0][j] != -1 && strs[i][j] < strs[i - 1][j])
                {
                    ans++;
                    strs[0][j] = -1;
                }
            }
        }
        return ans;
    }
};