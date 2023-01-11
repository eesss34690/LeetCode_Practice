class Solution {
public:
    vector<vector<int>> adjList;
    int dfs(int start, int dist, int priv, vector<bool>& hasApple) {
        int cur = 0, temp;
        for (auto &i : adjList[start])
        {
            if (i != priv)
            {
                temp = dfs(i, dist + 1, start, hasApple);
                if (temp)
                    cur += temp - dist;
            }
        }
        return (cur || hasApple[start]) ? dist + cur : 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adjList.resize(n);
        for (auto &i : edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        return dfs(0, 0, -1, hasApple) * 2;
    }
};
