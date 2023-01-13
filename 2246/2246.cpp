class Solution {
public:
    vector<vector<int>> adjList;
    int dfs(int idx, int prev, string &s, int &ans) {
        int cur_max_1 = 0, cur_max_2 = 0, temp;
        for (auto &i : adjList[idx])
        {
            if (i != prev)
            {
                temp = dfs(i, idx, s, ans);
                if (s[i] != s[idx])
                {
                    if (cur_max_1 < temp)
                    {
                        cur_max_2 = cur_max_1;
                        cur_max_1 = temp;
                    } else if (cur_max_2 < temp)
                        cur_max_2 = temp;
                }
            }
        }
        ans = max(1 + cur_max_1 + cur_max_2, ans);
        return 1 + cur_max_1;
    }
    int longestPath(vector<int>& parent, string s) {
        adjList.resize(s.length());
        int ans = 1;
        for (int i = 1; i < s.length(); i++)
        {
            adjList[i].push_back(parent[i]);
            adjList[parent[i]].push_back(i);
        }
        dfs(0, -1, s, ans);
        return ans;
    }
};
