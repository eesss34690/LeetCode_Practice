# 2466. Count Ways To Build Good Strings
###### tags: `leetcode`
## Description
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

- Example 1:

>Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
>>Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.

- Example 2:

>Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
>>Explanation: The good strings are "00", "11", "000", "110", and "011".

- Constraints:

>1 <= low <= high <= 105
1 <= zero, one <= low

## Solution
- The problem can be solved by using dynamic programming
- The issue is to combine the different length of string with static combination set for count of 1 or 0
- As the result, we can split it by remembering the count of possibility for the length `exactly` equal to some values
- One techic is that the differnece for `zero` and `one` does not affect the result. Swap the value for the two and we do not need to do comparison in the future
```cpp=
if (zero < one)
{
    i = zero;
    zero = one;
    one = i;
}
```
- The base case is the one among the size of `zero` and `one`. For the length among smaller size to bigger size, the combination is 1. The bigger size combination should be implemented after the iteration
```cpp=
for (i = one; i <= zero; i += one) dp[i] = 1;
dp[zero]++;
```
- After that, the combination would be the addition for `ending with zero` and `ending with one`, decrease the size of zero and one to get the rest of the combination substring count
```cpp=
for (; i <= high; i++) dp[i] = (dp[i - zero] + dp[i - one]) % 1000000007;
```
- After all, add all the values needed from `low` to `high`
```cpp=
for (i = low; i <= high; i++) ans = (ans + dp[i]) % 1000000007;
```