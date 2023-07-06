# 373. Find K Pairs with Smallest Sums
###### tags: `leetcode`
## Description
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

- Example 1:

>Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
>>Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

- Example 2:

>Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
>>Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

- Example 3:

>Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
>>Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]

- Constraints:

>1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 104

## Solution
- For the problem, we can use heap to help solve the order. The structure for the input should start from the most important one
```cpp=
priority_queue<vector<int>> q;
q.push({-nums1[0] - nums2[0], 0, 0});
```
- Because we need to remember which value is inserted, we also need to store the set that has already been finished
```cpp=
set<pair<int, int>> visited;
visited.insert({0, 0});
```
- The key structure for the solution iss as follow
    - We use the priority queue to store the possible solution
    - Each time when popping out one optimal pair, store it into the answer and check the two proximities for the one
    - If the two proximities do not touch the end, add them into the queue and mark as visited
```cpp=
while (!q.empty() && k--)
{
    auto it = q.top();
    q.pop();
    ans.push_back({nums1[it[1]], nums2[it[2]]});
    if (it[1] + 1 < nums1.size() && visited.count({it[1] + 1, it[2]}) == 0)
    {
        q.push({-nums1[it[1] + 1] - nums2[it[2]], it[1] + 1, it[2]});
        visited.insert({it[1] + 1, it[2]});
    }
    if (it[2] + 1 < nums2.size() && visited.count({it[1], it[2] + 1}) == 0)
    {
        q.push({-nums1[it[1]] - nums2[it[2] + 1], it[1], it[2] + 1});
        visited.insert({it[1], it[2] + 1});
    }
}
```