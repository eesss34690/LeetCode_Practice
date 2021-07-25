int dfs(int pos, bool last, bool eq, const vector<bool> &v, vector<vector<int> > &cache) {
    if (pos < 0) return 1;
    int &ans = cache[last * 2 + eq][pos];
    if (ans >= 0) return ans;
    ans = 0;
    if (!last && (!eq || v[pos])) ans += dfs(pos - 1, true, eq, v, cache);
    ans += dfs(pos - 1, false, eq && !v[pos], v, cache);
    return ans;
}

class Solution {
public:
    int findIntegers(int n) const {
        vector<bool> v;
        for (; n; n >>= 1) v.push_back(n & 1);
        vector<vector<int> > cache(4, vector<int>(v.size(), -1));
        return dfs(v.size() - 1, false, true, v, cache);
    }
};
