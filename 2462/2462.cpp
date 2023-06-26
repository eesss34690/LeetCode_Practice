class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int> left, right;
        int left_val, right_val, left_idx = -1, right_idx = costs.size(), cand = candidates;
        long long ans = 0;
        while (cand--)
        {
            left.push(-costs[++left_idx]);
            if (right_idx > candidates) right.push(-costs[--right_idx]);
        }
        while (k--)
        {
            right_val = (right.empty()) ? INT_MIN : right.top();
            left_val = (left.empty()) ? INT_MIN : left.top();
            if (left_val >= right_val)
            {
                left.pop();
                ans -= left_val;
                if (left_idx + 1 < right_idx) left.push(-costs[++left_idx]);
            }
            else
            {
                right.pop();
                ans -= right_val;
                if (left_idx + 1 < right_idx) right.push(-costs[--right_idx]);
            }
        }
        return ans;
    }
};
