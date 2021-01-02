class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        cout<<"[";
        if (nums.size()> 1)
        {
            k= k% nums.size();
            vector<int> a;
            a.assign(nums.begin()+ (nums.size()- k), nums.end());
            a.insert(a.end(), nums.begin(), nums.begin()+ (nums.size()- k));
            nums= a; 
            
            for (int i= 0; i< nums.size()- 1; i++)
            {
                cout<<nums[i]<<",";
            }
            cout<<nums[nums.size()-1]<<"]";
        }
        else
        {
            cout<<nums[0]<<"]";
        }
    }
};