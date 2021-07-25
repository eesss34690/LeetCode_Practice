# 600_Non-negative_Integers_without_Consecutive_Ones
###### tags: `leetcode` `600`
## Problem Statement
Given a positive integer n, return the number of the integers in the range [0, n] whose binary representations do not contain consecutive ones.

- Example 1:

> Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers $\leq 5$ with their corresponding binary representations:
```
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
```
> Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
- Example 2:

> Input: n = 1
Output: 2
- Example 3:

> Input: n = 2
Output: 3

- Constraints:
> $1 \leq n \leq 10^9$
## Solution
- The main concept is to use ```dynamic programming```. 
- In this part, the chart ```cache``` composes of
    - row: 4 rows representing 
        - whether it is the last row?
        - whether the current value now is the same as the target maximum.
    - column: the index for binary matching.
- The structure can be seen like this
```
|  1  |  0  |  0  |  1  |  0  |  <- qualified
|  1  | <--equal
|  0  | <--smaller
|  1  |  0  | <--only 0 can satifies
|  1  |  0  |  0  | <--equal
|  1  |  0  |  1  | <--bigger, incorrect
|  0  |  1  | <-- prev is not equal, thus qualified
```
- Can be seen as to check from the most significant bit and gets down one by one to get all the qualified solution.

- First change the decimal to binary
```cpp=
for (; n; n >>= 1) v.push_back(n & 1);
```
- The recursive function ```dfs``` can be constructed like below

```cpp=
int dfs(int pos, bool last, bool eq, const vector<bool> &v, vector<vector<int> > &cache)
// pos: the current index
// last: the previous bit for the number
// eq: for now the number is equal to or smaller than the required maximum
// cache: stored dp table
```
- Let the ```[last * 2 + eq][pos]``` be the place to store the value. If it has not been calculated yet, the value would be ```-1``` in initial declaration. Elsewise return the value.

```cpp=
int &ans = cache[last * 2 + eq][pos];
if (ans >= 0) return ans;
```
- Add the value to dp if it is not calculated. Shift to next digit and put in parameters.

```cpp=
ans += dfs(pos - 1, false, eq && !v[pos], v, cache);
```
- If it is not the last bit and the former is ```0``` or the value is ```0```, add one more condition.

```cpp=
if (!last && (!eq || v[pos])) ans += dfs(pos - 1, true, eq, v, cache);
```