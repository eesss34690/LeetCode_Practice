class Solution {
public:
    vector<bool> visit;
    vector<vector<int>> to, from;
    int ans;
    void dfs(int n) {
        visit[n] = true;
        for (auto &i : to[n])
        {
            if (!visit[i])
            {
                ans++;
                dfs(i);
            }
        }
        for (auto &i : from[n])
            if (!visit[i])
                dfs(i);
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        visit.resize(n);
        to.resize(n);
        from.resize(n);
        for (auto &i : connections)
        {
            to[i[0]].push_back(i[1]);
            from[i[1]].push_back(i[0]);
        }
        ans = 0;
        dfs(0);
        return ans;
    }
};
