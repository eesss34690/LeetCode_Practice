# 605. Can Place Flowers
###### tags: `leetcode`
## Description
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

- Example 1:

>Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

- Example 2:

>Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

- Constraints:

>$1 \leq flowerbed.length \leq 2 \times 10^4$
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
$0 \leq n \leq flowerbed.length$

## Solution
- The problem can be done by using `greedy algorithm`
- By linearly go through all the node, place the flower if consecutive 0 is present or it is the begining of 0. As the result, orignally the previous stamp is `0`
```cpp=
int prev = 0;

if (flowerbed[i] == 0)
{
    if (prev == 0)
    {
        prev = 2;
        n--;
    }
    else prev = 0;
}
```
- For the `1`, remember to check if the last one places a new flower, append it back if it is the case. Also, the early checking for the goal should be done here because when the `0` occurs, it may be to be added back in the following `1`.
```cpp=
else
{
    if (prev == 2) n++;
    prev = 1;
    if (n <= 0) return true;
}
```
- Also, because there may be possibility that the number of `0` is so many that the flower is over-planted at the first place in `0`, Check `n <= 0` instead of `n == 0`
