class Solution {
public:
    vector<vector<int>> graph;
    void dfs(int node, vector<bool>& visit) {
        visit[node] = true;
        for (auto &i : graph[node])
        {
            if (visit[i] == false)
                dfs(i, visit);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() + 1 < n)
            return -1;
        graph.resize(n);
        vector<bool> visit(n);
        for (auto &i : connections)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == false)
            {
                cnt++;
                dfs(i, visit);
            }
        }
        return cnt - 1;
    }
};
