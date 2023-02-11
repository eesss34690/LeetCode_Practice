class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, -1);
        vector<vector<pair<int, int>>> graph(n);
        queue<pair<int, int>> q{{{0, 0}}};

        for (vector<int>& edge : redEdges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].emplace_back(v, 1);
        }

        for (vector<int>& edge : blueEdges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].emplace_back(v, 2);
        }
        for (int step = 0; !q.empty(); ++step)
            for (int sz = q.size(); sz > 0; --sz) {
                auto [u, prevColor] = q.front();
                q.pop();
                ans[u] = ans[u] == -1 ? step : ans[u];
                for (auto& [v, edgeColor] : graph[u]) {
                    if (v == -1 || edgeColor == prevColor)
                        continue;
                    q.emplace(v, edgeColor);
                    v = -1;
                }
            }
    return ans;
  }
};