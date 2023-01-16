class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            int &end = ans.back()[1];
            if(end >= intervals[i][0])
                end = max(intervals[i][1], end);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};
