class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_= 0, l= 0;
        for (int i= 1; i< prices.size(); i++)
        {
            if (prices[i]> prices[i- 1])
            {
                l= max(l+ prices[i]- prices[i- 1], l);
            }
            else
            {
                max_+= l;
                l= 0;
            }
        }
        max_+= l;
        return max_;
    }
};