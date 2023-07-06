# 1140. Stone Game II
###### tags: `leetcode`
## Description
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

- Example 1:

>Input: piles = [2,7,9,4,4]
Output: 10
>>Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 

- Example 2:

>Input: piles = [1,2,3,4,5,100]
Output: 104

- Constraints:

>1 <= piles.length <= 100
1 <= piles[i] <= 104

## Solution
- The problem can be solved by dynamic programming. Because the issue is mainly about the cumulative sum, calculate it beforehead
```cpp=
vector<int> suffixSums(n + 1);
for (i = n - 1; i >= 0; i--) suffixSums[i] = suffixSums[i + 1] + piles[i];
```
- Then, for each subset in the piles, calculate the score
    - If `m` can contain all the sum in the subset, strately use that as the biggest answer to the subset
```cpp=
if (i + 2 * m >= n) dp[i][m] = suffixSums[i];
```
- Elsewise, consider the result for the opponent. The opponent should get the greedily maximum of the current result from the substring of the rest taken from `x`. In the `dp[i + x]` array, the maximum is the one with the most taken, so the value is `dp[i + x][max(x, m)]`
```cpp=
opponentScore = dp[i + x][max(x, m)];
```
- The score for the current user is the rest of the score, so it can be done by substraction
```cpp=
score = suffixSums[i] - opponentScore;
```
- The dp result should be the maximum one among the whole array
```cpp=
dp[i][m] = max(dp[i][m], score);
```