class Solution {
public:
    int ans = 0;
    void maxReq(vector<vector<int>>& requests, vector<int>& in, int start, int n, int cnt) {
        if (start == requests.size())
        {
            for (int i = 0; i < n; i++)
                if (in[i] != 0) return;
            ans = max(ans, cnt);
        }
        else
        {
            in[requests[start][0]]--;
            in[requests[start][1]]++;
            maxReq(requests, in, start + 1, n, cnt + 1);
            in[requests[start][0]]++;
            in[requests[start][1]]--;
            maxReq(requests, in, start + 1, n, cnt);
        }
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> in(n);
        maxReq(requests, in, 0, n, 0);
        return ans;
    }
};
