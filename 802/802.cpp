class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> out(graph.size()), ans;
        vector<vector<int>> rev(graph.size());
        queue<int> q;
        for (int i = 0; i < graph.size(); i++)
        {
            for (auto &j : graph[i]) rev[j].push_back(i);
            out[i] = graph[i].size();
            if (out[i] == 0) q.push(i);
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (auto &j : rev[cur]) if (--out[j] == 0) q.push(j);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
