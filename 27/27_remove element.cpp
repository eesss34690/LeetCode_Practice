class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (vector<int>::iterator i= nums.begin(); i!= nums.end();)
        {
            if (*i== val)
            {
                nums.erase(i);
            }
            else
                i++;
        }
        cout<< nums.size()<<", nums = [";
        for (int i= 0; i< nums.size(); i++)
        {
            cout<<nums[i];
            if (i!= nums.size()- 1)
            {
                cout<<",";
            }
        }
        cout<<"]";
        return nums.size();
    }
};