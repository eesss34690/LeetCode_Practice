# 258. Add Digits
###### tags: `leetcode`
## Description
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

- Example 1:

>Input: num = 38
Output: 2
>>Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

- Example 2:

>Input: num = 0
Output: 0

- Constraints:

>$0 \leq num \leq 2^{31} - 1$

- Follow up: Could you do it without any loop/recursion in O(1) runtime?

## Solution
- The problem can be solved by the iteration, but there are actually some patterns that we can follow
- The only possibilities of the answers are from `0` to `9`. Because we do not have multiple `0` to construct a number, the answer `0` only appears when the original value is `0`. Others can be seen as a loop from `1` to `9`.
```cpp=
if ( num == 0 ) return 0;
return num % 9 == 0 ? 9 : num % 9;
```