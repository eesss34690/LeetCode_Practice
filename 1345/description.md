# 1345. Jump Game IV
###### tags: `leetcode`
## Description
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

`i + 1` where: $i + 1 < arr.length$.
`i - 1` where: $i - 1 \leq 0$.
`j` where: $arr[i] == arr[j]$ and $i != j$.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

- Example 1:

>Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
>>Explanation: You need three jumps from index `0 --> 4 --> 3 --> 9`. Note that index 9 is the last index of the array.

- Example 2:

>Input: arr = [7]
Output: 0
>>Explanation: Start index is the last index. You do not need to jump.

- Example 3:

>Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
>>Explanation: You can jump directly from index 0 to index 7 which is last index of the array.

- Constraints:

>$1 \leq arr.length \leq 5 \times 10^4$
$-10^8 \leq arr[i] \leq 10^8$

## Solution
- This problem can be solved by using `map` to store the same value index and use BFS to to the treversal
```cpp=
unordered_map<int, vector<int>> graph;
for (int i = 0; i < arr.size(); i++)
    graph[arr[i]].push_back(i);
```
- The testcases in the problem are demanding, often cause `TLE`. The acceleration methods nust be used
- To begin with, there is no need to iterate through those nodes that have been through because there is no chance for that iteration to win after the one done before. Keep a vector to store whether it has beeb gone through
```cpp=
vector<bool> visit(arr.size());
q.push(0);
visit[0] = 1;
```
- For each node on the iteration, return when it is the last one or about to be the last one
```cpp=
if (front == arr.size() - 1)
    return cnt;
if (front + 2 == arr.size())
    return cnt + 1;
```
- Push back the neighborhood of the array if it is not iterated yet
```cpp=
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
```
- In the same value map, add the value into queue if it is not iterated yet and check if it is the end of the array
```cpp=
for (auto &i : graph[arr[front]])
    if (visit[i] == 0)
    {
        if (i + 1 == arr.size())
            return cnt + 1;
        q.push(i);
        visit[i] = 1;
    }
```
- The **key** for this problem is to **clear** the vector in the map because there may be tons of the same value in the same iteration. And not cleaning them makes the whole proceudure check on the visit mark for the vector again and again
```cpp=
graph[arr[front]].clear();
```