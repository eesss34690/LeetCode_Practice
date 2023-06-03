class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> subordinates(n);
        for (int i = 0; i < n; i++) if (headID != i) subordinates[manager[i]].push_back(i);
        queue<int> q;
        q.push(headID);
        int ans = 0, temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            for (auto &i : subordinates[temp])
            {
                q.push(i);
                informTime[i] += informTime[temp];
                ans = max(ans, informTime[i]);
            }
        }
        return ans;
    }
};