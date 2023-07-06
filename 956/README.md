## Description
You are installing a billboard and want it to have the largest height. The billboard will have two steel supports, one on each side. Each steel support must be an equal height.

You are given a collection of rods that can be welded together. For example, if you have rods of lengths 1, 2, and 3, you can weld them together to make a support of length 6.

Return the largest possible height of your billboard installation. If you cannot support the billboard, return 0.

- Example 1:

>Input: rods = [1,2,3,6]
Output: 6
>>Explanation: We have two disjoint subsets {1,2,3} and {6}, which have the same sum = 6.

- Example 2:

>Input: rods = [1,2,3,4,5,6]
Output: 10
>>Explanation: We have two disjoint subsets {2,3,5} and {4,6}, which have the same sum = 10.

- Example 3:

>Input: rods = [1,2]
Output: 0
>>Explanation: The billboard cannot be supported, so we return 0.

- Constraints:

>>1 <= rods.length <= 20
1 <= rods[i] <= 1000
sum(rods[i]) <= 5000

## Solution
- The problem can be solved by using dynamic programming. We need to designate a system to accomodate the value such that the sum and the rest of the value can both be considered
- The map `unordered_map<int, int> dp` is the mapping between the difference of the two sum. We can construct the two sum as tall sum and low sum
- For each step when iterating through all the rods, copy the dictionary in order to clarify between the newly added pair and the original pair
```cpp=
unordered_map<int, int> cur(dp);
```
- There are two possibilities for putting the current rods. We can put it at the tall sum or the low sum. If we put it at the tall sum, we would add the current height difference by `rods[i]`. The mapping value should be the maximum height with the height differnece with the previous value or the current value
```cpp=
dp[d + x] = max(dp[d + x],cur[d]);
```
- If we put it at the low sum, we would substract the current heigth difference by `rods[i]`. The mapping value should be the maximum height with the height difference with the previous vallue or the current value plus the minimum of the current height difference or the rod length
```cpp=
dp[abs(d - x)] = max(dp[abs(d - x)], cur[d] + min(d, x));
```