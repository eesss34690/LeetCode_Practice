# 1751. Maximum Number of Events That Can Be Attended II
###### tags: `leetcode`
## Description
You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

Return the maximum sum of values that you can receive by attending events.

- Example 1:
![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60048-pm.png)

>Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
Output: 7
>>Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.

- Example 2:
![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60150-pm.png)

>Input: events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
Output: 10
>>Explanation: Choose event 2 for a total value of 10.
Notice that you cannot attend any other event as they overlap, and that you do not have to attend k events.

- Example 3:
![](https://assets.leetcode.com/uploads/2021/01/10/screenshot-2021-01-11-at-60703-pm.png)

>Input: events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
Output: 9
>>Explanation: Although the events do not overlap, you can only attend 3 events. Pick the highest valued three.

- Constraints:

>1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106

## Solution
- The problem is relately harder, but the concept is still `dynamic programming`
- To solve the question, the key issue is the `ending time`
- By sorting the starting time, we need to find the closest one for the next move with the maximum value
- With the constraint of the total moves we can do, the answer for still having `k` moves are
    - Do not that the current stamp `i` : $dp[i+1][k]$
    - Take this stamp `i` : $dp[nxt\_stamp][k-1] + events[i][2]$
- In order to find the next stamp for the current progress, we can use binary search in order to boost the speed
    - If the current target's starting time is too early, shift right
    - Elsewise just shift left
```cpp=
int search (vector<vector<int>>& events, int stop, int idx) {
    int l = idx, r = events.size() - 1, m;
    while (l < r)
    {
        m = l + (r - l) / 2;
        if (events[m][0] > stop) r = m;
        else l = m + 1;
    }
    return (l < events.size() && events[l][0] > stop) ? l : -1;
}
```
- With the searching method, we can count the current starting stamp with the left `k`
```cpp=
int memo (vector<vector<int>>& dp, vector<vector<int>>& events, int n, int k, int idx) {
    if (idx == n || k == 0) return 0;
    if (dp[idx][k] != -1) return dp[idx][k];
    int ans = memo(dp, events, n, k, idx + 1);
    int stamp = search(events, events[idx][1], idx + 1);
    ans = max(ans, events[idx][2] + ((stamp == -1) ? 0 : memo(dp, events, n, k - 1, stamp)));
    return dp[idx][k] = ans;
}
```
