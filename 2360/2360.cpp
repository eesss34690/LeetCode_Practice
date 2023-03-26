class Solution {
public:
    vector<int> visit;
    int global_cnt;
    int dfs(int idx, int cnt, vector<int>& edges)
    {
        visit[idx] = cnt;
        if (edges[idx] == -1)
        {
            global_cnt = cnt + 1;
            return -1;
        }
        if (visit[edges[idx]] == 0) return dfs(edges[idx], cnt + 1, edges);
        if (visit[edges[idx]] > global_cnt)
        {
            global_cnt = visit[edges[idx]];
            return cnt + 1 - visit[edges[idx]];
        }
        global_cnt = cnt + 1;
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        visit.resize(n);
        int cur = -1, temp;
        global_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == 0)
            {
                temp = dfs(i, global_cnt + 1, edges);
                cur = max(cur, temp);
            }
        }
        return cur;
    }
};
