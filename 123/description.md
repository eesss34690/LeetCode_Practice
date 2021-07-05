# 123_Best_Time_to_Buy_and_Sell_Stock_III
###### tags: `leetcode` `123`
## Problem Statement
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

- Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

 

- Example 1:

> Input: prices = [3,3,5,0,0,3,1,4]
> Output: 6
> Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

- Example 2:

> Input: prices = [1,2,3,4,5]
> Output: 4
> Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
> Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
- Example 3:

> Input: prices = [7,6,4,3,1]
> Output: 0
> Explanation: In this case, no transaction is done, i.e. max profit = 0.
- Example 4:

> Input: prices = [1]
> Output: 0
 
- Constraints:

> 1 <= prices.length <= 10^5^
> 0 <= prices[i] <= 10^5^

## Solution
- There is one more chance for transaction, after the normal procedure of looking for 1 transaction, there are 4 possibilities for adding 1 more transaction.
    1. Add 1 before the current one.
    2. Add 1 adter the current one.
    3. Split the current one into 2 transactions.
    4. Remain the same.
- As the result, when selecting the first transaction, store the begin and the end of the index.
```cpp=
// max_: the count of the gain
// temp: the lower bound candidate
// c: control of whether to write new lower bound
// change the lower and upper bound index when max_ is changed
for (int i= 1; i< prices.size(); i++)
{
    if (l+ prices[i]- prices[i- 1]> 0)
    {
        l+= prices[i]- prices[i- 1];
        if (c)
        {
            temp= i;
            c= 0;
        }
    }
    else
    {
        l= 0;
        c= 1;
    }
    if (max_< l)
    {
        max_= l;
        p2= i+ 1;
        p1= temp;
    }
}
```
- To compare whether adding one more transaction, the prerequisite is that there is transaction and the number of index need to be bigger than 1
```cpp=
if (p2!= 0&& prices.size()> 1)
```
- The 3 possibilities is considered:
1. Add one before transaction: count one transaction from the beginning till the lower bound.
```cpp=
for (int i= 1; i< p1; i++)
{
    l= max(l+ prices[i]- prices[i- 1], 0);
    max_l= max(max_l, l);
}
```
2. Add one after transaction: count one transaction from the upper bound till the end.
```cpp=
for (int i= p2; i< prices.size(); i++)
{
    l= max(l+ prices[i]- prices[i- 1], 0);
    max_r= max(max_r, l);
}
```
3. Split can be seperated into 2 cases:
    - Split from the smallest one among the middle
    - Split from the biggest one among the middle
Since the ```min_element()``` and ```max_element()``` gives the first smallest element without scanning all the index of the smallest element, the ```while``` loop is required. 
```cpp=
vector<int>::iterator a, b;
b= min_element(prices.begin()+ p1, prices.begin()+ p2- 1);
do
{
    a= max_element(prices.begin()+ p1, b);
    temp= (*a> *b)? prices[p2- 1]- *b+ *a- prices[p1- 1]: 0; 
    max_m= max(max_m, temp);
    b= find(b+ 1, prices.begin()+ p2- 1, *b);
}while (b!= prices.begin()+ p2- 1);
```
```cpp=
b= max_element(prices.begin()+ p1, prices.begin()+ p2- 1);
do
{
    a= min_element(b, prices.begin()+ p2- 1);
    temp= (*a< *b)? prices[p2- 1]- *a+ *b- prices[p1- 1]: 0; 
    max_m= max(max_m, temp);
    b= find(b+ 1, prices.begin()+ p2- 1, *b);
}while (b!= prices.begin()+ p2- 1);
```
- After all the possibilities, compare the result.
```cpp=
max_l= max(max_l, max_r);
max_= max(max_, max_+ max_l);
return max(max_, max_m);
```