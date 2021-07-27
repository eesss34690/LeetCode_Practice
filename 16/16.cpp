class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto it= lower_bound(nums.begin(), nums.end(), target/ 3);
        if (it== nums.begin())
            return nums[0]+ nums[1]+ nums[2];
        if (it== nums.end())
            return *(nums.end()- 1)+ *(nums.end()- 2)+ *(nums.end()- 3);
        vector<int> lo(nums.begin(), it);
        vector<int> hi(it, nums.end());
        int close= INT_MAX, temp;
        /*
        for (auto &i: lo)
            cout<<i<<" ";
        cout<<endl;
        for (auto &i: hi)
            cout<<i<<" ";
        cout<<endl;
        // lo: 1, hi: 2
        // lo: 2, hi: 1
        */
        for (auto &i: lo)
        {
            for (vector<int>::iterator j= hi.begin(); j!= hi.end()- 1; j++)
            {
                for (vector<int>::iterator k= j+ 1; k!= hi.end(); k++)
                {
                    temp= i+ *j+ *k;
                    //cout<<i<<" "<< *j<<" "<< *k<<" "<<temp<<endl;
                    if (temp> target)
                    {
                        if (temp-  target< abs(close))
                            close= temp- target;
                        break;
                    }
                    else if (target== temp)
                    {
                        return target;
                    } 
                    else if (target- temp< abs(close))
                    {
                        close= temp- target;
                    } 
                    //cout<<close<<endl;
                }
            }
        }
        for (auto &i: hi)
        {
            for (vector<int>::iterator j= lo.end()- 1; j!= lo.begin(); j--)
            {
                for (vector<int>::iterator k= j- 1; k- lo.begin()> -1; k--)
                {
                    temp= i+ *j+ *k;
                    //cout<<i<<" "<< *j<<" "<< *k<<" "<<temp<<endl;
                    if (temp< target)
                    {
                        if (target- temp< abs(close))
                            close= temp- target;
                        break;
                    }
                    else if (target== temp)
                    {
                        return target;
                    } 
                    else if (temp- target< abs(close))
                    {
                        close= temp- target;
                    } 
                    //cout<<close<<endl;
                }
            }
        }
        if (hi.size()> 2)
        {
            temp= hi[0]+ hi[1]+ hi[2];
            if (temp- target< abs(close))
                return temp;            
        }

        return close+ target;
    }
};
