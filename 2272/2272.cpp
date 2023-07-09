class Solution {
public:
    int largestVariance(string s) {
        int ans = 0, val, haveB, firstB;
        unordered_set<char> sets(begin(s), end(s));
        for (auto &a : sets)
        {
            for (auto &b : sets)
            {
                val = 0, haveB = 0, firstB = 0;
                for (char &c : s)
                {
                    val += c == a;
                    if (c == b)
                    {
                        haveB = 1;
                        if (firstB && val >= 0) firstB = 0;
                        else if (--val < 0)
                        {
                            firstB = 1;
                            val = -1;
                        }
                    }
                    ans = max(ans, haveB ? val : 0);
                }
            }
        }
        return ans;
    }
};
