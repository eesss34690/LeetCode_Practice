# 877_Stone_Game
###### tags: `leetcode` `877`
## Problem Statement
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
- Example 1:

> Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 
- Constraints:

> $2 \leq piles.length \leq 500$
piles.length is even.
$1 \leq piles[i] \leq 500$
sum(piles) is odd.
## Solution
- Actually this question is kind of odd, because there must be a winner, and Alex chooses first, there is no chance for Lee no win at all if they choose optimally. Therefore straightly return 1 will solve this.
- But to practice, I still come up with ```dp solution```.
- To wrap up this question, the first player choose either ```left``` or ```right```, which means the other has the same optimal score for first choice of ```left+1 & right``` or ```left& right+1```.
- Therefore, the dp table should contain the optimal solution for the player to be the first and has choices between ```l``` and ```r``` and also the second player with the same range of choices.
- To finish this chart, help the player to have a choice between left and right and calculate the following optimal score for each.

```cpp=
pair<int, int> leftPick = dp(piles, left + 1, right);
pair<int, int> rightPick = dp(piles, left, right - 1);
```
- If the player chooses left, first one has score ```leftPick.second+ piles[left]```. Else if he chooses right, first one has score ```rigthPick.second+ piles[right]```
- The following chart shows the result of each scenarios.

||first player|second player|
|-|-|-|
|first chooses left|leftPick.second+ piles[left]|leftPick.first|
|first chooses right|leftPick.second+ piles[left]|rightPick.first|

- Therefore, compare the first one' s benefit and see which solution he wants and fill in the chart.

```cpp=
if (piles[left] + leftPick.second > piles[right] + rightPick.second) {
    return memo[left][right] = make_pair(piles[left] + leftPick.second, leftPick.first);
}
return memo[left][right] = make_pair(piles[right] + rightPick.second, rightPick.first);
```

- And the score pair is ```dp(piles, 0, piles.size() - 1)```