# 121_Best_Time_to_Buy_and_Sell_Stock
###### tags: `leetcode` `121`
## Problem Statement
You are given an array prices for which prices[i] is the price of a given stock on the ith day.

You are only permitted to complete at most one transaction. In other words, you can buy one and sell one share of the stock. You cannot sell a stock before you buy one.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

- Example 1:

> Input: prices = [7,1,5,3,6,4]
> Output: 5
> Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
> The answer is not 7-1 = 6, as selling price needs to be larger than buying price.
- Example 2:

> Input: prices = [7,6,4,3,1]
> Output: 0
> Explanation: In this case, no transactions are done and the max profit = 0.
 
- Constraints:

> 1 <= prices.length <= 10^5^
> 0 <= prices[i] <= 10^4^

## Solution
- Calculate the distance between the relevant array and the positive distance calculated so far from the smallest one.
```cpp=
l= max(l+ prices[i]- prices[i- 1], 0);
```
- Remember the largest result so far.
```cpp=
max_= max(max_, l);
```