class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort (piles.begin(), piles.end());
        int ans= 0;
        for (int i= piles.size()/ 3; i< piles.size(); i+= 2)
        {
            ans+= piles[i];
        }
        return ans;
    }
};