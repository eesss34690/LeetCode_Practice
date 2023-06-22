# 714. Best Time to Buy and Sell Stock with Transaction Fee
###### tags: `leetcode`
## Description
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

- Example 1:

>Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
>>Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
- Example 2:

>Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

- Constraints:

>1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

## Solution
- The problem can be solved intuively. There are two options, one the timestamp you may buy the stock or sell the stock
- For buying, the revenue should be the previously sold income substract the current price
- For selling, the revenue should be the previously bought income plus the current price substracted by the fee
- In each iteration, we can choose to use the current one or not, so simply get the maximum one is fine
```cpp=
int buy = -prices[0];
int sell = 0;
for(int i = 1 ; i < prices.size(); i++)
{
    buy = max(buy, sell - prices[i]);
    sell = max(sell, prices[i] + buy - fee);
}
```
- Finally, we can not buy in the last timestamp, only the selling one is okay. Compare the selling one with 0 for the result
```cpp=
return max(sell,0);
```