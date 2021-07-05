class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int count1= 0;
        int count2= 0;
        int may1, may2;           
        for (int i= 0; i< nums.size(); i++)
        {
            if (nums[i]== may1)
            {
                count1++;
            }
            else if (nums[i]== may2)
            {
                count2++;
            }
            else if (count1== 0)
            {
                may1= nums[i];
                count1++;
            }
            else if (count2== 0)
            {
                may2= nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i= 0; i< nums.size(); i++)
        {
            if (may1== nums[i]) count1++;
            else if (may2== nums[i]) count2++;
        }
        if (count1> nums.size()/ 3)
        {
            ans.push_back(may1);
        }
        if (count2> nums.size()/ 3)
        {
            ans.push_back(may2);
        }
        return ans;       
    }
};