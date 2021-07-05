class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()> 2)
        {
            bool s= 0;
            for (vector<int>::iterator i = nums.begin(); nums.size()> 2&& i!= nums.end()-1; i++)
            {
                if (!s)
                {           
                    if ((i!= nums.end()-2)&& ((*i == *(i+ 1))&& (*i== *(i+ 2))))
                    {
                        nums.erase(i);
                        s = 1;
                    }                
                }
                else
                {
                    if (*i ==*(i+1))
                    {
                        nums.erase(i);
                        i--;
                    }
                    else
                    {
                        s= 0;
                    }
                }

            }
        }
        cout<<nums.size()<<", nums = [";
        for (int i= 0; i< nums.size()- 1; i++)
        {
            cout<<nums[i]<<",";
        }
        cout<<nums[nums.size()-1]<<"]";
        return nums.size();
    }
};