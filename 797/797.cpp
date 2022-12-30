class Solution {
public:
    void dfs(vector<vector<int>>& sol, vector<int> temp, vector<vector<int>>& graph, int starter, int num)
    {
        temp.push_back(starter);
        if (starter == num)
        {
            sol.push_back(temp);
            return;
        }
        for (auto i : graph[starter])
            dfs(sol, temp, graph, i, num);       
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> sol;
        vector<int> temp;
        int num = graph.size();
        if (num == 0)
            return sol;
        dfs(sol, temp, graph, 0, num - 1);
        return sol;
    }
};