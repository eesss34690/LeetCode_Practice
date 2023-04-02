class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++)
        {
            auto bound = ceil(double(success) / double(spells[i]));
            auto temp = lower_bound(potions.begin(), potions.end(), bound);
            spells[i] = potions.end() - temp;
        }
        return spells;
    }
};