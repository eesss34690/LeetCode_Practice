class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxAns = 0, minAns = 0;
        k--;
        vector<long long> comb;
        for (int i = 1; i < weights.size(); i++)
            comb.push_back(weights[i] + weights[i - 1]);
        sort(comb.begin(), comb.end());
        for (int i = 0; i < k; i++)
        {
            minAns += comb[i];
            maxAns += *(comb.end() - i - 1);
        }
        return maxAns - minAns;
    }
};
