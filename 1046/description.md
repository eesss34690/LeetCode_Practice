# 1046. Last Stone Weight
###### tags: `leetcode`
## Description
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with $x \leq y$. The result of this smash is:

If $x = y$, both stones are destroyed, and
If $x \neq y$, the stone of weight x is destroyed, and the stone of weight y has new weight $y - x$.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

- Example 1:

>Input: stones = [2,7,4,1,8,1]
Output: 1
>>Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

- Example 2:

>Input: stones = [1]
Output: 1

- Constraints:

>$1 \leq stones.length \leq 30$
$1 \leq stones[i] \leq 1000$

## Solution
- Simply stimulate the process. But the key point is to generate the list that can be ordered by the value
- The `std` to used is `priority queue`. The top is the maximum one. So each time pop two maximum up and compare the value. Put the difference into the queue again if they are different
```cpp=
while (pq.size() > 1)
{
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    if (a != b) pq.push(a - b);
}
```
- Return `0` if the two values are different, and otherwise the last one in the queue.
```cpp=
return pq.empty() ? 0 : pq.top();
```