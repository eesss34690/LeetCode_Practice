# 879. Profitable Schemes
###### tags: `leetcode`
## Description
There is a group of n members, and a list of various crimes they could commit. The ith crime generates a profit[i] and requires group[i] members to participate in it. If a member participates in one crime, that member can't participate in another crime.

Let's call a profitable scheme any subset of these crimes that generates at least minProfit profit, and the total number of members participating in that subset of crimes is at most n.

Return the number of schemes that can be chosen. Since the answer may be very large, return it modulo 109 + 7.

- Example 1:

>Input: n = 5, minProfit = 3, group = [2,2], profit = [2,3]
Output: 2
>>Explanation: To make a profit of at least 3, the group could either commit crimes 0 and 1, or just crime 1.
In total, there are 2 schemes.

- Example 2:

>Input: n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
Output: 7
>>Explanation: To make a profit of at least 5, the group could commit any crimes, as long as they commit one.
There are 7 possible schemes: (0), (1), (2), (0,1), (0,2), (1,2), and (0,1,2).

- Constraints:

> $1 \leq n \leq 100$
$0 \leq \text{minProfit} \leq 100$
$1 \leq \text{group.length} \leq 100$
$1 \leq \text{group}[i] \leq 100$
$\text{profit.length} == \text{group.length}$
$0 \leq \text{profit}[i] \leq 100$

## Solution
- The problem can be simplified by using `dynamic programming`
- To clarify the declaration of the dp array, the `dp[i][j]` means the i profit with j people invloved
```cpp=
vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1, 0));
```
- Therefore, the `dp[0][0]` means there is no profit with on person, which is 1 posibility, obviously
```cpp=
dp[0][0] = 1;
```
- In the whole iteration, iterate through all the crimes. Adding with all the combination of the profits, if it is more than the `minProfit`, just make it in `minProfit` categories. Pick the profit combination and number of people, then add on the original count.
```cpp=
for (int k = 0; k < group.size(); k++) {
    // Retrieve the group of people and the profit in this crime
    int g = group[k], p = profit[k];
    // In all the profit combinaiton, add on this profit
    for (int i = minProfit; i >= 0; i--)
        // In all the possible people resorce (start from all people can use minus the people used in this crime, to 0)
        for (int j = n - g; j >= 0; j--)
            // The people and profit combination result is the original answer plus the added profit and people set possibility
            dp[min(i + p, minProfit)][j + g] = (dp[min(i + p, minProfit)][j + g] + dp[i][j]) % mod;
}
```
- Finally, get the last row, which is the profit more than or equal to `minProfit` from no people to all the people resource
```cpp=
for (auto x: dp[minProfit]) res = (res + x) % mod;
```