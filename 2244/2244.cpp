class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        if (tasks.size() == 1)
            return -1;
        int cur = tasks[0], cnt = 1, ans = 0;
        for (int i = 1; i < tasks.size(); i++)
        {
            if (cur != tasks[i])
            {
                if (cnt == 1)
                    return -1;
                ans += ((cnt - 1) / 3) + 1;
                cur = tasks[i];
                cnt = 1;
            } else
                cnt++;
        }
        if (cnt == 1)
            return -1;
        ans += ((cnt - 1) / 3) + 1;
        return ans;
    }
};