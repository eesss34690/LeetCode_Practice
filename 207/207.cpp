class Solution {
public:
    void dfs(vector<unordered_set<int>>& graph, vector<int>& disclude, int numCourses) {
        disclude[numCourses] = -1;
        for (auto &i : graph[numCourses]) if (--disclude[i] == 0) dfs(graph, disclude, i);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> disclude(numCourses, 0);
        for (auto &i : prerequisites)
        {
            graph[i[1]].insert(i[0]);
            disclude[i[0]]++;
        }
        while (--numCourses >= 0)
        {
            if (disclude[numCourses] == 0) dfs(graph, disclude, numCourses);
        }
        for (int i = 0; i < disclude.size(); i++)
        {
            if (disclude[i] > 0) return false;
        }
        return true;
    }
};
