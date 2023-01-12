class Solution {
public:
    vector<vector<int>> adjList;
    vector<int> dfs(int idx, int prev, vector<vector<int>> &edges, vector<int> &ans, string &labels)
    {
        vector<int> cur(26), temp;
        for (auto &i : adjList[idx])
        {
            if (i != prev)
            {
                temp = dfs(i, idx, edges, ans, labels);
                transform(cur.begin(), cur.end(), temp.begin(), cur.begin(), plus<int>());
            }

        }
        cur[labels[idx] - 'a']++;
        ans[idx] = cur[labels[idx] - 'a'];
        return cur;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n);
        adjList.resize(n);
        for (auto &i : edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        dfs(0, -1, edges, ans, labels);
        return ans;
    }
};
