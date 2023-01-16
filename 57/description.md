# 57. Insert Interval
###### tags: `leetcode`
## Description
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

- Example 1:

>Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

- Example 2:

>Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
>>Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

- Constraints:

>0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

## Solution
- Sort the vector and add the new interval in
```cpp=
intervals.push_back(newInterval);
sort(intervals.begin(), intervals.end());
ans.push_back(intervals[0]);
```
- Check the vales between, the original array, add it to the answer if it is not in the gap, if it is among the gap, choose the bigger value and keeps challenging the new one.
```cpp=
for (int i = 1; i < intervals.size(); i++){
    int &end = ans.back()[1];
    if(end >= intervals[i][0])
        end = max(intervals[i][1], end);
    else
        ans.push_back(intervals[i]);
}
```
