class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size()== 1)
            return 1;
        int ans= ratings.size();
        int m= 0, temp= 0, ma= 2e+4;
        for (int i= 1; i< ratings.size(); i++)
        {
            if (ratings[i]< ratings[i- 1])
            {
                if (temp== 0) 
                {
                    ans+= i- m;
                    if (ma<= i- m&& ratings[m]!= ratings[m- 1])
                        ans++;
                }
                else
                {
                    temp= 0;
                    m= i;
                }
            }
            else if (ratings[i]> ratings[i- 1])
            {
                temp++;
                ans += temp;
                m= i;
                ma= temp;
            }
            else
            {
                temp= 0;
                m= i;
            }
            //cout<<i<<": "<<ans<<" "<<temp<<" "<<m<<" "<<ma<<endl;
        }
        return ans;
    }
};