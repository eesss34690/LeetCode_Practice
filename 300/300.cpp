class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans(nums.size(),1e4);
        int size= 0, l, r, m;
        for (auto &i: nums)
        {
            if (i< ans[size])
            {
                l= 0, r= size;
                while(l< r)
                {
                    m=(l+ r)/ 2;
                    if (ans[m]< i)
                        l= m+ 1;
                    else
                        r= m;
                }
                ans[l]= i;
            }
            else if (i!= ans[size])
            {
                ans[++size]= i;
            }
        }
        return size+1;
    }
};



