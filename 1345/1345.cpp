class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1)
            return 0;
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < arr.size(); i++)
            graph[arr[i]].push_back(i);
        int front, cnt = 0;
        queue<int> q;
        vector<bool> visit(arr.size());
        q.push(0);
        visit[0] = 1;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                front = q.front();
                q.pop();
                if (front == arr.size() - 1)
                    return cnt;
                if (front + 2 == arr.size())
                    return cnt + 1;
                if (front > 0 && visit[front - 1] == 0)
                {
                    q.push(front - 1);
                    visit[front - 1] = 1;
                }
                if (front + 1 < arr.size() && visit[front + 1] == 0)
                {
                    q.push(front + 1);
                    visit[front + 1] = 1;
                }
                for (auto &i : graph[arr[front]])
                    if (visit[i] == 0)
                    {
                        if (i + 1 == arr.size())
                            return cnt + 1;
                        q.push(i);
                        visit[i] = 1;
                    }
                graph[arr[front]].clear();
            }
            cnt++;
        }
        return cnt;
    }
};