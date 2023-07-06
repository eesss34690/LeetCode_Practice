# 875. Koko Eating Bananas
###### tags: `leetcode`
## Description
Koko loves to eat bananas. There are n piles of bananas, the `ith` pile has `piles[i]` bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer `k` such that she can eat all the bananas within `h` hours.

- Example 1:

>Input: piles = [3,6,7,11], h = 8
Output: 4

- Example 2:

> Input: piles = [30,11,23,4,20], h = 5
Output: 30

- Example 3:

>Input: piles = [30,11,23,4,20], h = 6
Output: 23

- Constraints:

>$1 \leq piles.length \leq 10^4$
$piles.length \leq h \leq 10^9$
$1 \leq piles[i] \leq 10^9$

## Solution
- The problem can be done by using `BFS` to search for the ideal number
- The smallest speed required is `0` and the maximum would be `max time in vector` because there is no use if the speed is faster than that one
```cpp=
long long l = 0, r = *max_element(piles.begin(), piles.end());
```
- When iterating, count the time required to finish the banana by the speed. Ajust the threshold by the value. Make sure the right one after the loop is the smallest qualified one and the left, just one smaller than it, is not qualified
```cpp=
while (r - l > 1)
{
    m = (l + r) / 2;
    temp = 0;
    for (auto &i : piles)
        temp += (i % m == 0) ? i / m : i / m + 1;
    if (temp <= h)
        r = m;
    else l = m;
}
```
- After that, because the left one is not qualified, return right
