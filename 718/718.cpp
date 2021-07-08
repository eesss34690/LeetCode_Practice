class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int first= nums1.size(), second= nums2.size(), temp= 0;
        vector<vector<int>> dp(first, vector<int>(second));
        dp[0][0]= (nums1[0]== nums2[0])? 1:0;
        for (int i= 1; i< second; i++)
        {
            dp[0][i]= (nums1[0]== nums2[i])? 1:0;
        }
        for (int i= 1; i< first; i++)
        {
            dp[i][0]= (nums1[i]== nums2[0])? 1:0;
            for (int j= 1; j< second; j++)
            {
                if (nums1[i]== nums2[j])
                {
                    dp[i][j]= 1+ dp[i-1][j-1];
                    temp= (temp< dp[i][j])? dp[i][j]: temp;
                }
                else
                {
                    dp[i][j]= 0;
                }
            }
        }
        return temp;
    }
};
