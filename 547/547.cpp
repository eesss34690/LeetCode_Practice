class Solution {
public:
    void dfs(int i, int n, vector<vector<int>>& isConnected, vector<int>&visited) {
        visited[i] = true;
        vector<int> adj;
        for (int j = 0; j < n; j++) if (isConnected[i][j]) adj.push_back(j);
        for (auto &j : adj) if (!visited[j]) dfs(j, n, isConnected, visited);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        vector<int> visited(len);
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, len, isConnected, visited);
            }
        }
        return ans;
    }
};
