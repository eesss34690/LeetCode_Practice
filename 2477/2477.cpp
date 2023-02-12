class Solution {
public:
    vector<vector<int>> graph;
    vector<int> visit;
    long long int dfs(int idx, int &seats, long long int &ans)
    {
        long long int left = 1;
        visit[idx] = 1;
        for (auto &i : graph[idx])
            if (!visit[i])
                left += dfs(i, seats, ans);
        if (idx == 0)
            return left;
        ans += ((left - 1) / seats) + 1;
        return left;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        graph.resize(roads.size() + 1);
        visit.resize(graph.size());
        for (auto &i : roads)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        long long int ans = 0;
        dfs(0, seats, ans);
        return ans;
    }
};