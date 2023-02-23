class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> project(profits.size());
        for (int i = 0; i < profits.size(); i++)
            project[i] = {capital[i], profits[i]};
        sort(project.begin(), project.end());
        int cur = 0;
        priority_queue<int> q;
        while (k--)
        {
            for (; cur < project.size() && project[cur].first <= w ; cur++)
                q.push(project[cur].second);
            if (q.empty())
                return w;
            w += q.top();
            q.pop();
        }
        return w;
    }
};