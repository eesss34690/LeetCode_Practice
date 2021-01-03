class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (!nums.size())
        {
            return 1;
        }
        else
        {
            bool use[300] = {0};
            for (vector<int>::iterator i= nums.begin(); i!= nums.end(); i++)
            {
                if (*i> 0&& *i< 301)
                {
                    use[*i- 1]= 1;
                }
                
            }
            for (long long int i= 0; i< 300; i++)
            {
                if (use[i]== 0)
                {
                    return i+ 1;
                }
            }
            return 301;
        }
    }
};