class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
            return 0;
        for (vector<int>::iterator i = nums.begin()+1; i!= nums.end();)
        {
            if (*i == *(i-1))
            {
                nums.erase(i);
            }
            else i++;
        }
        cout<<nums.size()<<" , nums = [";
        for (int i= 0; i< nums.size(); i++)
        {
            cout<<nums[i];
            if (i!= nums.size()- 1)
            {
                cout<<",";
            }
            else
                cout<<"]";
        }
        return nums.size();
    }

};