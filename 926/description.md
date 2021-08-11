# 926_Flip_String_to_Monotone_Increasing
###### tags: `leetcode` `926`
## Problem Statement
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

Return the minimum number of flips to make s monotone increasing.

- Example 1:

> Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
- Example 2:

> Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.
- Example 3:

> Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
 
- Constraints:

> $1 \leq s.length \leq 10^5$
s[i] is either '0' or '1'
## Solution
- This is a dynamic programming problem.
- You can regard the string to be added one by one.
- Everytime when the digit is added, there re 2 posibilities.
	- Keep all the digits as 1 in the back.
	- Keep the whole string as 0
- Keep a record as the number of 1 to be turned as 0 for the case of 2
- Use one variable to record keep the legitimate one with the last one added.
- See which one is better and update the last one.
```cpp=
for (auto c : s) {
    if (c == '1') counter++; //number of 1 in the string
    else flips++; //last legitimate solution count
            
    flips = min(flips, counter);
        }
```