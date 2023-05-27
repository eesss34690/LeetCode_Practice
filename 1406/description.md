# 1406. Stone Game III
###### tags: `leetcode`
## Description
Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

- Example 1:

>Input: values = [1,2,3,7]
Output: "Bob"
>>Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

- Example 2:

>Input: values = [1,2,3,-9]
Output: "Alice"
>>Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.

- Example 3:

>Input: values = [1,2,3,6]
Output: "Tie"
>>Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

- Constraints:

>1 <= stoneValue.length <= 5 * 104
-1000 <= stoneValue[i] <= 1000

## Solution
- The problem can be done by using dynamic programming by setting the minmax solution for the two opponents.
- The two players use greedy algorithm for the calculated result when they do each turn. We can regard the dp array as `Alice initiated play score`. So if the result is used when Bob initiates the game, the score would be `-1 * score`.
- Because the result is related to the cumulated sum of the substring, add them together in the array
```cpp=
cumulated.back() = stoneValue.back();
for (i = stoneValue.size() - 2; i >= 0 ; i--) cumulated[i] = cumulated[i + 1] + stoneValue[i];
```
- In each iteration, calculate the three possiblities `take one`, `take two`, `take three`. Set the result as the cumulated sum when the result exceeds. Elsewise the answer should be the cumulated sunstring with the rest of the substring initiated by Bob
```cpp=
for (i = stoneValue.size() - 1; i >= 0 ; i--)
{
    for (j = 3; j > 0; j--)
    {
        if (i + j >= stoneValue.size()) ans[i] = cumulated[i];
        else ans[i] = max(cumulated[i] - cumulated[i + j] - ans[i + j], ans[i]);
    }
}
```
- For the final result, the answer should be seen by the value.
```cpp=
if (ans[0] > 0) return "Alice";
else if (ans[0] < 0) return "Bob";
return "Tie";
```