class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int temp= 1;
        ans.push_back(0);
        ans.push_back(1);
        for (int i= 1; i< n; i++)
        {
            temp*= 2;
            for (int j= ans.size()- 1; j> -1; j--)
            {
                ans.push_back(temp+ ans[j]);
            }
        }
        return ans;
    }
};