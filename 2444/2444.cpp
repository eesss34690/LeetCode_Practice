class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int> minSet, maxSet;
        long long int dp[nums.size()], frontLine = 0, last;
        if (minK == maxK && nums[0] == minK)
        {
            dp[0] = 1;
            minSet.push_back(0);
        }
        else
        {
            dp[0] = 0;
            if (nums[0] == minK)
                minSet.push_back(0);
            else if (nums[0] == maxK)
                maxSet.push_back(0);
            else if (nums[0] < minK || nums[0] > maxK)
                frontLine++;
        }
        last = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > minK && nums[i] < maxK)
                dp[i] = dp[i - 1];
            else if (nums[i] < minK || nums[i] > maxK)
            {
                frontLine = i + 1;
                minSet.clear();
                maxSet.clear();
                dp[i] = 0;
            }
            else if (nums[i] == minK)
            {
                if (minK == maxK)
                {
                    if (minSet.empty())
                        dp[i] = 1;
                    else
                        dp[i] = i - minSet[0] + 1;
                }
                else if (!maxSet.empty())
                    dp[i] = maxSet.back() - frontLine + 1;
                else dp[i] = 0;
                minSet.push_back(i);
            }
            else
            {
                if (!minSet.empty())
                    dp[i] = minSet.back() - frontLine + 1;
                else dp[i] = 0;
                maxSet.push_back(i);
            }
            last += dp[i];
        }
        return last;
    }
};