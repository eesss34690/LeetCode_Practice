class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        int u, v;
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            for (auto x : adj[u])
            {
                int node = x.first;
                double prob = x.second;
                double newProb = dist[u] * prob;
                if (newProb > dist[node])
                {
                    dist[node] = newProb;
                    q.push(node);
                }
            }
        }
        return dist[end];
    }
};
