class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visit;
    vector<long long int> cnt;
    void dfs(int i)
    {
        if (visit[i] == 0)
        {
            ++cnt.back();
            visit[i] = 1;
            for (auto &j : graph[i])
                dfs(j);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        visit.resize(n);
        for (auto &i : edges)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == 0)
            {
                cnt.push_back(0);
                dfs(i);
            }
        }
        if (cnt[0] == n) return 0;
        long long int ans = 0, temp = 0;
        for (int i = 0; i < cnt.size(); i++)
        {
            ans += cnt[i] * (n - temp - cnt[i]);
            temp += cnt[i];
        }
        return ans;
    }
};