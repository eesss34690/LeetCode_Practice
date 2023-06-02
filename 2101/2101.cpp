class Solution {
public:
    void dfs(vector<vector<bool>>& graph, int i, vector<bool>& stamp, int& ans) {
        stamp[i] = true;
        ans++;
        for (int j = 0; j < graph.size(); j++)
        {
            if (j == i) continue;
            if (graph[i][j] && !stamp[j]) dfs(graph, j, stamp, ans);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<bool>> graph(bombs.size(), vector<bool>(bombs.size()));
        int i, j;
        long long temp;
        for (i = 0; i < bombs.size(); i++)
        {
            for (j = i + 1; j < bombs.size(); j++)
            {
                temp = pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2);
                graph[i][j] = temp <= pow(bombs[i][2], 2);
                graph[j][i] = temp <= pow(bombs[j][2], 2);
            }
        }
        int ans = 1;
        for (i = 0; i < bombs.size(); i++)
        {
            vector<bool> stamp(bombs.size());
            int temp = 0;
            dfs(graph, i, stamp, temp);
            ans = max(ans, temp);
        }
        return ans;
    }
};
